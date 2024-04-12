# Simple Docker

Introduction to docker. Developing a simple docker image for your own server.

1. [Ready-made docker](#part-1-ready-made-docker) 
2. [Operations with container](#part-2-operations-with-container) 
3. [Mini web server](#part-3-mini-web-server) 
4. [Your own docker](#part-4-your-own-docker) 
5. [Dockle](#part-5-dockle) 
6. [Basic Docker Compose](#part-6-basic-docker-compose)

# 

## Part 1. Ready-made docker

##### Take the official docker image from **nginx** and download it using `docker pull`.

![docker pull](01/1.1.png)

##### Check for the docker image with `docker images`

![docker images](01/1.2.png)

##### Run docker image with `docker run -d [image_id|repository]`

![docker run -d](01/1.3.png)

##### Check that the image is running with `docker ps`

![docker ps](01/1.4.png)

##### View container information with `docker inspect [container_id|container_name]`

![docker inspect id](01/1.5.png)
![docker inspect nginx](01/1.6.png)


[docker_inspect_id.json](01/docker_inspect_id.json) \
[docker_inspect_id.json](01/docker_inspect_nginx.json)


##### From the command output define and write in the report the container size, list of mapped ports and container ip

![docker inspect](01/1.7.png)
![docker inspect](01/1.8.png)
![docker inspect](01/1.9.png)

##### Stop docker image with `docker stop [container_id|container_name]`

![docker stop](01/1.10.png)

##### Check that the image has stopped with `docker ps`

![docker ps](01/1.11.png)

##### Run docker with mapped ports 80 and 443 on the local machine with *run* command

![docker run](01/1.12.png)

##### Check that the **nginx** start page is available in the browser at *localhost:80*

![docker page](01/1.13.png)

##### Restart docker container with `docker restart [container_id|container_name]`

![docker restart](01/1.14.png)

##### Check in any way that the container is running

![docker ps](01/1.15.png)

#

## Part 2. Operations with container

##### Read the *nginx.conf* configuration file inside the docker container with the *exec* command

![docker exec](02/2.1.png)

##### Create a *nginx.conf* file on a local machine

![Create nginx.conf](02/2.2.png)

##### Configure it on the */status* path to return the **nginx** server status page

![Configure nginx.conf](02/2.3.png)

##### Copy the created *nginx.conf* file inside the docker image using the `docker cp` command

![Cp nginx.conf](02/2.4.png)

##### Restart **nginx** inside the docker image with *exec*

![Restart nginx](02/2.5.png)

##### Check that *localhost:80/status* returns the **nginx** server status page

![Check localhost](02/2.6.png)

##### Export the container to a *container.tar* file with the *export* command

![Export container](02/2.7.png)

##### Stop the container

![Export container](02/2.8.png)

##### Delete the image with `docker rmi [image_id|repository]`without removing the container first

![Delete image](02/2.9.png)

##### Delete stopped container

![Delete stopped container](02/2.10.png)

##### Import the container back using the *import*command

![Import the container back](02/2.11.png)

##### Run the imported container

![Run the imported container](02/2.12.png)

##### Check that *localhost:80/status* returns the **nginx** server status page

![Check that *localhost:80/status*](02/2.13.png)

#

## Part 3. Mini web server

##### Write a mini server in **C** and **FastCgi** that will return a simple page saying `Hello World!`

![a mini server in **C** and **FastCgi**](03/3.1.png)

##### Run the written mini server via *spawn-fcgi* on port 8080

![Run the written mini server via *spawn-fcgi* on port 8080](03/3.2.png)

##### Write your own *nginx.conf* that will proxy all requests from port 81 to *127.0.0.1:8080*

![nginx.conf](03/3.3.png)

##### Check that browser on *localhost:81* returns the page you wrote

![nginx.conf](03/3.4.png)

#

## Part 4. Your own docker

#### Write your own docker image that:
##### 1) builds mini server sources on FastCgi from [Part 3](#part-3-mini- web-server)
##### 2) runs it on port 8080
##### 3) copies inside the image written *./nginx/nginx.conf*
##### 4) runs **nginx**.

![nginx.conf](04/4.1.png)

##### Build the written docker image with `docker build`, specifying the name and tag

![nginx.conf](04/4.2.png)

##### Check with `docker images` that everything is built correctly

![nginx.conf](04/4.3.png)

##### Run the built docker image by mapping port 81 to 80 on the local machine and mapping the *./nginx* folder inside the container to the address where the **nginx** configuration files are located (see [Part 2](#part-2-operations-with-container))

![nginx.conf](04/4.4.png)

##### Check that the page of the written mini server is available on localhost:80

![nginx.conf](04/4.5.png)

##### Add proxying of */status* page in *./nginx/nginx.conf* to return the **nginx** Яserver status

![nginx.conf](04/4.6.png)

##### Restart docker image
*If everything is done correctly, after saving the file and restarting the container, the configuration file inside the docker image should update itself without any extra steps

##### Check that *localhost:80/status* now returns a page with **nginx** status
