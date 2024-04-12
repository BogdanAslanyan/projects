#!/bin/bash
gcc mini_server.c -lfcgi -o mini_server
spawn-fcgi -p 8080 ./mini_server
nginx -g "daemon off;"
