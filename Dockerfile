FROM debian:buster

RUN apt-get update && apt-get install -y \
    cmake gcc gcc-multilib g++ g++-multilib make doxygen bash grub-common \
    xorriso \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt/next-divel

CMD ["bash", "build.sh"]