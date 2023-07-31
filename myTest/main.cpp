#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include "../7zlib/7zlib.h"

struct TestInfo
{
	std::thread::id id;
	std::string content;
};

void TestCallback(float percent, void* user)
{
	TestInfo* ti = static_cast<TestInfo*>(user);
	std::cout << "threadId: " << ti->id << " " << ti->content << " " << percent << "%" << std::endl;
}


int main()
{
	bool result = SevenZip::Initialize();
	if (result)
	{

		TestInfo tic;
		tic.id = std::this_thread::get_id();
		tic.content = "Compress";

		TestInfo tiuc;
		tiuc.id = std::this_thread::get_id();
		tiuc.content = "Uncompress";

		//SevenZip::ResultCode resultCode1 = SevenZip::Compress(L"E:/coding/data/ÉòÐÇ-¸ß×¯  ¡¢ÉòÐÇ-Ìï×¯ÏßÂ·", L"E:/coding/data/model.gim", TestCallback, &tic);
		//std::cout << "threadId: " << tic.id << " compress resultCode[" << resultCode1 << "]" << std::endl;

		SevenZip::ResultCode resultCode2 = SevenZip::Uncompress(L"E:/coding/data/ÉòÐÇ-¸ß×¯  ¡¢ÉòÐÇ-Ìï×¯ÏßÂ·.gim", L"E:/coding/data/ÉòÐÇ-¸ß×¯  ¡¢ÉòÐÇ-Ìï×¯ÏßÂ·", TestCallback, &tiuc);
		std::cout << "threadId: " << tiuc.id << " uncompress resultCode[" << resultCode2 << "]" << std::endl;

		//SevenZip::ResultCode resultCode1 = compressFunc(L"E:/coding/data/model", L"E:/coding/data/model.gim", nullptr, nullptr);
		//SevenZip::ResultCode resultCode2 = uncompressFunc(L"E:/coding/data/¹ÅÏª±äµçÕ¾GIMÄ£ÐÍ.gim", L"E:/coding/data/¹ÅÏª±äµçÕ¾GIMÄ£ÐÍ", nullptr, nullptr);
		//std::thread t1(TestLib, L"D:\\temp\\tt\\fan.exe", L"D:\\temp\\tt\\fan.7z", L"D:\\temp\\tt\\out7z");
		//std::thread t2(TestLib, L"E:/workspace/data/model", L"E:/workspace/data/model.gim", L"E:/workspace/data/hhhh");

		//t1.join();
		//t2.join();
	}
	else
	{
		std::cout << "initialize error!" << std::endl;
	}

	SevenZip::Uninitialize();

	return 0;
}