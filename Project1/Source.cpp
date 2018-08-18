#include<iostream>
#include<thread>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <chrono>
#include <vector>

#define MAX_SIZE 1024
//#define RADIUS 5
#define THREAD_COUNT 4


using namespace std;

static int RADIUS;
static int arr[MAX_SIZE][MAX_SIZE];
static int arr1[MAX_SIZE][MAX_SIZE];


void printArray(int a[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void createMatrix() {
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			arr[i][j] = rand() % 10;
		}
	}
	//printArray(arr);
}

void avgNeighbour(int indexX, int indexY, int radius) {
	int sum = 0;
	int count = (2 * radius + 1)*(2 * radius + 1);
	for (int i = indexX - radius; i <= indexX + radius&&i<MAX_SIZE; i++) {
		for (int j = indexY - radius; j <= indexY + radius && j < MAX_SIZE; j++) {
			if (i >= 0&&j>=0) {
				sum += arr[i][j];
			}
		}
	}
	arr1[indexX][indexY] = sum / count;
}

void normalMethod() {
	cout << "Normal Method"<<endl;
	auto startTime = chrono::steady_clock::now();
	
	for (int i = 0; i<MAX_SIZE; i++)
		for (int j = 0; j<MAX_SIZE; j++)
			avgNeighbour(i, j, RADIUS);

	auto endTime = chrono::steady_clock::now();

	//printArray(arr1);
	cout << "Elapsed Time::" << chrono::duration<double, milli>(endTime - startTime).count() << " ms" << endl;
}

void threadJob(int threadNo) {
	int threadIteration = MAX_SIZE / THREAD_COUNT;
	for(int i = 0; i<threadIteration; i++)
		for (int j = 0; j < MAX_SIZE; j++) {
			avgNeighbour(threadIteration*threadNo, j, RADIUS);
		}
}

void multiThreadedMethod() {
	cout <<endl<< "MultiThreaded Method"<<endl;
	vector<thread> workers;
	auto startTime = chrono::steady_clock::now();
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		workers.push_back(thread(threadJob,i));
	}

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		workers[i].join();
	}

	auto endTime = chrono::steady_clock::now();
	//printArray(arr1);
	cout << "Elapsed Time::" << chrono::duration<double, milli>(endTime - startTime).count() << " ms" << endl;
}

void ompMethod() {
	cout << endl << "OMP Method" << endl;
	auto startTime = chrono::steady_clock::now();

	#pragma omp parallel for num_threads(THREAD_COUNT) 
	for(int i=0;i<MAX_SIZE;i++) 
		for (int j = 0; j < MAX_SIZE; j++) {
			avgNeighbour(i, j, RADIUS);
		}

	auto endTime = chrono::steady_clock::now();
	//printArray(arr1);
	cout << "Elapsed Time::" << chrono::duration<double, milli>(endTime - startTime).count() << " ms" << endl;

}

int main() {

	cout << "Enter the radius::";
	cin >> RADIUS;
	createMatrix();
	
	normalMethod();

	multiThreadedMethod();

	ompMethod();
	_getch();
	return 0;
}