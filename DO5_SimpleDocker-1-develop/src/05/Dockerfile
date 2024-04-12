FROM nginx:1.21.0

# Set working directory
WORKDIR /home/

# Switch to root user temporarily
USER root

# Copy necessary files
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c /home/mini_server.c
COPY ./run.sh /home/run.sh

# Install required packages and clean up
RUN apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Change ownership and permissions
RUN chown -R nginx:nginx /etc/nginx/nginx.conf \
    && chown -R nginx:nginx /var/cache/nginx \
    && chown -R nginx:nginx /home \
    && touch /var/run/nginx.pid \
    && chown -R nginx:nginx /var/run/nginx.pid \
    && chmod +x run.sh \
    && chmod u-s /usr/bin/passwd \
    && chmod u-s /usr/bin/newgrp \
    && chmod g-s /usr/bin/chage \
    && chmod u-s /usr/bin/gpasswd \
    && chmod u-s /bin/su \
    && chmod u-s /bin/mount \
    && chmod g-s /usr/bin/wall \
    && chmod u-s /usr/bin/chsh \
    && chmod g-s /usr/bin/expiry \
    && chmod u-s /usr/bin/chfn \
    && chmod u-s /bin/umount \
    && chmod g-s /sbin/unix_chkpwd

# Switch back to the nginx user
USER nginx

# Healthcheck
HEALTHCHECK --interval=5m --timeout=3s CMD curl --fail http://localhost || exit 1

# Set the entrypoint
ENTRYPOINT ["sh", "./run.sh"]
