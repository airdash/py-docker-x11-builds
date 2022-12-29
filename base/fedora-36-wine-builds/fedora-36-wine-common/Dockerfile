FROM pydockerx11/base/fedora:36-nvidia
USER root
RUN dnf install -y xdotool cabextract gstreamer1-plugins-{bad-*,good-*,base} gstreamer1-plugin-openh264 gstreamer1-libav --exclude=gstreamer1-plugins-bad-free-devel
ADD files/pulse-client.conf /etc/pulse/client.conf
WORKDIR /home/sandbox
USER sandbox
