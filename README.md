# Selixca!

To Run the tasks in dockers container use following command :
>**docker build -t silexica . && docker run -it --rm silexica /bin/bash**

*Dockerfile build may take several minutes to enter in container.*

To see the output of the all tasks use "jobs.sh" script.
>**./jobs.sh**

To run tasks on host machine use following commands.
>**g++ ./T_1_c++/circus/circus.cpp -o circus.out && ./T_1_c++/circus/circus.out**
>**python3 ./T_2_python/script.py**
>**groovy ./T_3_groovy/script.groovy**



Following versions are used for tasks completion.
>**g++ 9.2.1**
>**python 3.7.5**
>**groovy 2.4.6 - JVM 11.0.5**
