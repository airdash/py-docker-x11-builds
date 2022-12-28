FROM archlinux

RUN pacman -Syu --noconfirm  && pacman -Fy && pacman -S libx11 --noconfirm
ADD files/XlibNoSHM.c /tmp

RUN useradd -m sandbox 

# RUN cc -fPIC -m32 -shared -o /usr/local/lib/XlibNoSHM.so /tmp/XlibNoSHM.c
# RUN cc -fPIC -shared -o /usr/local/lib/XlibNoSHM.so /tmp/XlibNoSHM.c

