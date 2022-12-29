FROM pydockerx11/base/fedora:36-wine-common
ADD cache/wine-ge-custom-latest.tar.xz /opt
WORKDIR /opt
RUN find /opt -maxdepth 1 -mindepth 1 -type d -exec mv {} wine \;
# ADD files/*mono*.msi /usr/share/wine/mono/
# ADD files/*gecko*.msi /usr/share/wine/gecko/
ADD files/pulse-client.conf /etc/pulse/client.conf
WORKDIR /home/sandbox
USER sandbox
