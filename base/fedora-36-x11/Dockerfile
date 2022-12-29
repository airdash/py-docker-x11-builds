FROM pydockerx11/base/fedora:36
USER root
RUN yum install -y kmod xdotool

## Extra x86_64 common game dependencies go here, so long as they're not too egregious
RUN yum install -y SDL2 alsa-lib pulseaudio-libs libXcursor libXrandr libXScrnSaver libwayland-egl libwayland-cursor xgamma vulkan-tools vulkan-loader xdotool xwininfo ncurses-libs gtk3

## WINE dependency dumpster fire
# FIXME: Remove and put in WINE builder, as soon as I determine which of these should be considered part of this build.

RUN yum install -y SDL2_ttf.i686 SDL2_mixer.i686 pulseaudio-libs.i686 libXcursor.i686 libXrandr.i686 libXScrnSaver.i686 vulkan-loader.i686 ncurses-libs.i686 openssl-libs.i686 libFAudio libFAudio.i686 libxcrypt.i686 gstreamer1.i686 gstreamer1 libva.i686 libvkd3d libvkd3d.i686 libtiff.i686 gstreamer1-plugins-base gstreamer1-plugins-base.i686 gnutls.i686 cups-libs.i686 gd.i686 gd libexif.i686 libexif libgphoto2 libgphoto2.i686 libimagequant.i686 libimagequant libpcap.i686 libtiff libv4l.i686 libv4l.x86_64 libva libwebp.i686 libwebp mesa-libOSMesa.i686 mesa-libOSMesa.x86_64 unixODBC.i686 unixODBC.x86_64 avahi avahi-libs.i686 libXcomposite.i686 libXinerama.i686 libXpm.i686 libXpm.x86_64 libdaemon libtool-ltdl.i686 libtool-ltdl.x86_64 lockdev.i686 lockdev.x86_64 mpg123-libs.x86_64 nss-mdns.i686 nss-mdns.x86_64 readline.i686 libFAudio.x86_64 libva.x86_64 openldap.i686 cyrus-sasl-lib.i686 libdb.i686 mpg123-libs.i686

## And other things

RUN yum install -y alsa-plugins-pulseaudio alsa-plugins-pulseaudio.i686 dbus-x11 libidn libGLU
USER sandbox
