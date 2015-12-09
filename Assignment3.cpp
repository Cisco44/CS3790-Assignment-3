#include "ReaderWriter"

int value;
int readCount;
sem_t readSem;
sem_t accessSem;

int main ()
{
	srand(time(NULL));
	sem_init(&readSem, 0, 1);
	sem_init(&accessSem, 0, 1);

	value = 0; readCount = 0;
	pthread_t threadID [6];

	// Loop that initiallizes both the readers and writer threads.
	for(int i = 0; i < 6; i++)
	{
		if( i % 2 == 0)		
			pthread_create(&threadID[i], NULL, Reader, (void *) i);
		else
			pthread_create(&threadID[i], NULL, Writer, (void *) i);
	}

	for(int i = 0; i < 6; i++)
	{
		pthread_join(threadID[i], NULL);
	}
}

