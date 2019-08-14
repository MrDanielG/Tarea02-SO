#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
    int status1, status2, status3, status4, status5, status6, status7, status8, status9, status10;

    if ((pid1=fork()) == 0 ){ /* Primer hijo */        

        if((pid5=fork()) == 0){/* Primer Nieto */

            if((pid3=fork()) == 0){/* Primer Bisieto */
                printf("Soy el primer Bisnieto O(%d, hijo de %d)\n", getpid(), getppid());
            }

            else {
                waitpid(pid3,&status3,0);
                printf("Soy el primer nieto T (%d, hijo de %d)\n", getpid(), getppid());
            }
        }

        else {
            waitpid(pid5,&status5,0);
            if((pid6=fork()) == 0){ /* Segundo Nieto */
                printf("Soy el segundo nieto O (%d, hijo de %d)\n", getpid(), getppid());
            }
                
            else{
                waitpid(pid6,&status6,0);
                printf("Soy el primer hijo Ñ (%d, hijo de %d)\n", getpid(), getppid());
            }
        }
    }

    else{ /*  padre */

        waitpid(pid1,&status1,0);
        if((pid2=fork()) == 0 ){ /* Segundo hijo  */
            

            if((pid7=fork()) == 0){ /* Tercer Nieto */
                printf("Soy el tercer nieto @ (%d, hijo de %d)\n", getpid(), getppid());
            }

            else {
                waitpid(pid7,&status7,0);
                printf("Soy el segundo hijo 2 (%d, hijo de %d)\n", getpid(), getppid());
            }
        }
        
        else{ /* padre */

            waitpid(pid2,&status2,0);

                if((pid4=fork()) == 0){/* Tercer Hijo */
                    

                    if((pid8=fork()) == 0){/* Cuarto Nieto */
                        printf("Soy el cuarto nieto 0 (%d, hijo de %d)\n", getpid(), getppid());
                    }

                    else {
                        waitpid(pid8,&status8,0);
                        if((pid9=fork()) == 0){ /* Quinto Nieto */
                            printf("Soy el quinto nieto 1 (%d, hijo de %d)\n", getpid(), getppid());
                        }
                
                        else{
                            waitpid(pid9,&status9,0);
                            printf("Soy el cuarto hijo 9 (%d, hijo de %d)\n", getpid(), getppid());
                        }
                    }
                }

                else {
                    /* Esperamos al primer hijo */
                        waitpid(pid1, &status1, 0);
                    /* Esperamos al segundo hijo */
                        waitpid(pid2, &status2, 0);
                    /* Esperamos al Tercer hijo */
                        waitpid(pid4, &status4, 0);
                        printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
                }
            
        }
    }

    return 0;
}
