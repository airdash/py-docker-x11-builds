#!/usr/bin/env python3

# This script reaches out to the arduino site and retrieves the current file version of the arduino for linux 64
# https://www.arduino.cc/en/software 

import requests
import argparse
import os
import sys
import time
from bs4 import BeautifulSoup

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--path", required=True, help="Path to check for and save the latest file to")
    return parser.parse_args()

def check_file_version(local_path, file):
    if os.path.exists(os.path.join(local_path, file)):
        return True
    else:
        return False

def get_remote_info(url, base_url, search):
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, "html.parser")
        linux_64_vs = soup.find(attrs = {'title':search})
        arduino_link = str(linux_64_vs['href'])
        arduino_file = arduino_link[len(base_url):]
        return arduino_link, arduino_file

def retrieve_file(url, file_path):
    print("Downloading %s" % url)
    response = requests.get(url)

    if response.status_code == 200:
        content = response.content
        with open(file_path, "wb") as f:
            f.write(content)

def create_symlink(file_path, symlink):
    if os.path.exists(symlink):

        base, ext = os.path.splitext(symlink)
        previous_symlink_name = base + "-previous" + ext
        os.rename(symlink, previous_symlink_name)

    os.symlink(file_path, symlink)

def check_latest_timestamp(file_path, file_name, max_age):

    current_timestamp = int(time.time())
    latest_timestamp = int(os.path.getmtime(os.path.join(file_path, file_name)))

    age = current_timestamp - latest_timestamp

    if age < max_age:
        return False
    else:
        return True

def main():

    args = parse_args()

    url = "https://www.arduino.cc/en/software"
    base_url = "https://downloads.arduino.cc/arduino-ide/"
    search = "Linux ZIP file 64 bits (X86-64)"
    symlink_name = "arduino-current-latest.zip"
    max_age = 86400

    timestamp_not_exceeded = check_latest_timestamp(args.path, symlink_name, max_age)

    if timestamp_not_exceeded:
        remote_url, remote_file_name = get_remote_info(url, base_url, search)
        is_latest_file = check_file_version(args.path, remote_file_name)
    else:
        print("Latest file for %s is too new, skipping." % symlink_name)
        sys.exit(0)

    if not is_latest_file:
        retrieve_file(remote_url, os.path.join(args.path, remote_file_name))
        create_symlink(remote_file_name, os.path.join(args.path, symlink_name))
    else:
        print("Latest version of %s already downloaded." % remote_file_name)

    print(remote_file_name)

if __name__ == '__main__':
    main()
