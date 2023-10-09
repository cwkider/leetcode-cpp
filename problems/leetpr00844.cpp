/*
* leetpr00844.cpp
* 844. Backspace String Compare
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int idx = 0;
		char *cs = NULL;
		char *ct = NULL;

		cs = (char*)malloc(sizeof(char) * 201);
		ct = (char*)malloc(sizeof(char) * 201);

		strcpy(cs, s.c_str());
		strcpy(ct, t.c_str());

		if (strlen(cs) > 1) {
			for (int i = 0; i < strlen(cs); ++i) {
				if (cs[i] == '#') {
					if (idx == i) idx -= 2;
					else idx -= 1;

					if (idx < 0) idx = -1;
				}
				else {
					idx++;
					if (idx + 1 < i) {
						cs[idx] = cs[i];
					}
				}
			}
			if (idx < 0) strcpy(cs, "");
			else cs[idx + 1] = '\0';
		}
		else {
			if (cs[0] == '#') strcpy(cs, "");
		}

		cout << "cs : " << cs << endl;

		idx = 0;
		if (strlen(ct) > 1) {
			for (int i = 0; i < strlen(ct); ++i) {
				if (ct[i] == '#') {
					if (idx == i) idx -= 2;
					else idx -= 1;

					if (idx < 0) idx = -1;
				}
				else {
					idx++;
					if (idx < i) {
						ct[idx] = ct[i];
					}
				}
			}
			if (idx < 0) strcpy(ct, "");
			else ct[idx + 1] = '\0';
		}
		else {
			if (ct[0] == '#') strcpy(ct, "");
		}

		cout << "ct : " << ct << endl;

		int ret = false;

		if (strcmp(cs, ct) == 0) {
			//cout << "s is not same with t !!!!!" << endl;
			ret = true;
		}

		free(cs);
		free(ct);

		return ret;
	}
};

int main00844() {
	string s, t;
	bool ret;
	Solution st;


	s = "ab#c";
	t = "ad#c";
	ret = st.backspaceCompare(s, t);
	cout << "ret : " << ret << endl;

	s = "a##c";
	t = "#a#c";
	ret = st.backspaceCompare(s, t);
	cout << "ret : " << ret << endl;

	s = "rheyggodcclgstf";
	t = "#rheyggodcclgstf";
	ret = st.backspaceCompare(s, t);
	cout << "ret : " << ret << endl;

	return 0;
}