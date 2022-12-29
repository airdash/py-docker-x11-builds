FROM pydockerx11/base/fedora:36-wine-common
USER root
ADD cache/wine-lutris-GE-Proton7-29-x86_64.tar.xz /opt
WORKDIR /opt
RUN find /opt -maxdepth 1 -mindepth 1 -type d -exec mv {} wine \;
# ADD files/*mono*.msi /usr/share/wine/mono/
# ADD files/*gecko*.msi /usr/share/wine/gecko/
WORKDIR /home/sandbox
USER sandbox
