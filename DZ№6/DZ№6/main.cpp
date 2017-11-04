#include "Classes.hpp"

int main()
{
	File* arr[4];
	arr[0] = new Video("porn");
	arr[1] = new Text("bible");
	arr[2] = new Image("my photo");
	arr[3] = new Image;
	for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		arr[i]->Open();
	}
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		delete[] arr[i];
	}
	system("pause");
	return 0;
}