#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
using namespace std;

map<string,set<int> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;

void check(map<string,set<int> > &mp,string &str){
	if(mp.find(str) != mp.end()){
		for(set<int>::iterator iter = mp[str].begin();iter != mp[str].end();++iter){
			printf("%07d\n",*iter);
		}	
	}
	else printf("Not Found\n");
}

int main(int argc, char *argv[])
{
	int n,m,mId,type;
	string title,author,key,pub,year;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&mId);
		char c = getchar();
		getline(cin,title);
		mpTitle[title].insert(mId);
		getline(cin,author);
		mpAuthor[author].insert(mId);
		while(cin>>key){
			mpKey[key].insert(mId);
			c = getchar();
			if(c == '\n')
				break;
		}
		getline(cin,pub);
		mpPub[pub].insert(mId);
		getline(cin,year);
		mpYear[year].insert(mId);
	}
	string temp;
	scanf("%d",&m);
	for(int i = 0;i<m;++i){
		scanf("%d: ",&type);
		getline(cin,temp);
		cout<<type<<": "<<temp<<endl;
		if(type == 1)
			check(mpTitle,temp);
		else if(type == 2)
			check(mpAuthor,temp);
		else if(type == 3)
			check(mpKey,temp);
		else if(type == 4)
			check(mpPub,temp);
		else check(mpYear,temp);
	}
	return 0;
}