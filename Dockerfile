FROM ubuntu 
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install python3 && \
    apt-get -y install g++ && \
    apt-get -y install groovy 
RUN mkdir -p /home/WorkSpace
COPY . /home/WorkSpace
WORKDIR /home/WorkSpace
