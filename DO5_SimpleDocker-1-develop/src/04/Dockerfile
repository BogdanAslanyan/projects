FROM nginx:latest
WORKDIR /home/
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c /home/mini_server.c
COPY ./run.sh /home/run.sh
RUN apt-get update; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    chmod +x run.sh
ENTRYPOINT ["./run.sh"]