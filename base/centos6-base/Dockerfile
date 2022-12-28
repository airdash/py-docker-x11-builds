FROM centos:6
RUN rm /etc/yum.repos.d/*
COPY files/CentOS-Base.repo /etc/yum.repos.d/
RUN yum update -y
RUN useradd -m -u 1000 sandbox
