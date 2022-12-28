FROM fedora:36 as builder

RUN dnf update -y  && dnf install libX11-devel gcc glibc-devel.i686 -y
ADD files/XlibNoSHM.c /tmp

RUN useradd -m sandbox 
RUN yum install dumb-init glibc.i686 strace -y

RUN cc -fPIC -m32 -shared -o /usr/local/lib/XlibNoSHM.so /tmp/XlibNoSHM.c
RUN cc -fPIC -shared -o /usr/local/lib64/XlibNoSHM.so /tmp/XlibNoSHM.c

FROM fedora:36
RUN dnf update -y
COPY --from=builder /usr/local/lib/XlibNoSHM.so /usr/local/lib
COPY --from=builder /usr/local/lib64/XlibNoSHM.so /usr/local/lib64
