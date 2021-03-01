#include "cstdlib"
#include "iostream"
#include "cstring"
#include "unistd.h"

using namespace std;

char* Cmd(const char *cmd)
{
	static char result[10240];
	FILE *fp = popen(cmd, "r");
	fgets(result, sizeof(result), fp);
	fgets(result, sizeof(result), fp);
	pclose(fp);
	return result;
}

void StartNode()
{
	system("node/linux-x64/Neuralium &");
}

void LoadWallet()
{
	system("./neuraliumcli LoadWallet");
}

void StartMining()
{
	system("./neuraliumcli StartMining");
}

bool Compare(const char *s1, const char *s2)
{
	for(int i=0;i<4;++i)
		if(s1[i] != s2[i])
			return false;
	return true;
}

bool IsMiningEnabled()
{
	char *result = Cmd("./neuraliumcli IsMiningEnabled");
	cout << Compare(result, "true") << endl;
	return Compare(result, "true");
}

void SyncBlockChain()
{
	system("./neuraliumcli SyncBlockchain true");
}

int main()
{
//	定时监控挖矿状态
	int disconnectTimes = -1;
	for(;;)
	{
		if(IsMiningEnabled() == false)
		{
			StartMining();
			++disconnectTimes;
		}
		cout << "disconnect: " << disconnectTimes << endl;
		SyncBlockChain();
		sleep(300);
	}
	return 0;
}
