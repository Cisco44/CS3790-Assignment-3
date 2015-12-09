#include "ReaderWriter"

void *Reader(void *arg)
{

	while(true)
	{
		// Access semaphore the readcounter integer.
		sem_wait(&readSem);
		++readCount;
		sleep(rand() % 10 + 1);
		if(readCount == 1)
			// Access semaphore for the value integer.
			sem_wait(&accessSem);

		sem_post(&readSem);

		cerr << "Reader #" << (int) arg << " entering critical section." << endl;
		cerr << "Reader #" << (int) arg << "'s value: " << value << endl;
		cerr << "Reader #" << (int) arg << " leaving critical section." << endl << endl;

		sem_wait(&readSem);

		--readCount;
		if(readCount == 0)
			sem_post(&accessSem);
		sem_post(&readSem);
		
		pthread_exit(NULL);
	}
}

void *Writer(void *arg)
{

	while(true)
	{
		sleep(rand() % 10 + 1);
		sem_wait(&accessSem);
	
		cerr << "Writer " << (int) arg << " entering critical section." << endl;
		++value;
		cerr << "Writer " << (int) arg << " leaving critical section." << endl << endl;

		sem_post(&accessSem);

		pthread_exit(NULL);
	}
}
