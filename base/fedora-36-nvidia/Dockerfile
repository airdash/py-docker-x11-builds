FROM pydockerx11/base/fedora:36-x11
USER root
ADD files/nvidia-driver.run /tmp/
RUN chmod 755 /tmp/nvidia-driver.run
RUN /tmp/nvidia-driver.run --no-kernel-module --accept-license --no-questions --silent --ui=none --no-x-check 
RUN rm /tmp/nvidia-driver.run
USER sandbox
