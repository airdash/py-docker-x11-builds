#FIXME: The whole thing

FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=America/Los_Angeles
RUN dpkg --add-architecture i386
RUN ln -s /usr/share/zoneinfo/America/Los_Angeles /etc/localtime
RUN mkdir -p /usr/local/lib64 /usr/local/lib
RUN apt-get clean && apt-get update && apt-get dist-upgrade -y 

# Add basic packages
RUN apt-get install software-properties-common strace libc6:i386 libstdc++6:i386 dumb-init -y

RUN useradd -m sandbox 
