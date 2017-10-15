#include<iostream>
#include<sstream>
#include<iterator>
#include<fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	deque < deque<string> > deck1,deck2,temp,deck;
	deque <string> buffer;
	deque <string> order;
	deque <int> orderi;
	string s,o;
	string pos;
	string delim = " ";
    fstream fin;
    int i=0,j=0,k=0,c =0 ,t1=0,t2=0,check =0;
    int oi;

    fin.open(argv[1],ios::in);
    while(getline(fin, s, '\n')){
    	if(s == "#"){
    		while(getline(fin, s, '\n')){
                size_t begin_pos=0, end_pos=s.find(delim); // locate the first delimiter in string
                while(end_pos!=-1) {
                    order.push_back(s.substr(begin_pos, end_pos-begin_pos)); // extract the sub-string before current delimiter
                    if(end_pos != s.size()-1)
                        begin_pos = end_pos+delim.size();
                    else
                        begin_pos = s.size();
                    end_pos = s.find(delim, begin_pos);// locate the next delimiter in string
                }
                if (begin_pos != s.size())
                    order.push_back(s.substr(begin_pos, s.size()-begin_pos));  // extract the last sub-string
    		}
    		for(i= 0;i<order.size();i++){
                stringstream ss(order[i]);
    			ss>> oi;
    			orderi.push_back(oi);
    		}
    	}
		else{
            size_t begin_pos=0, end_pos=s.find(delim); // locate the first delimiter in string
            while(end_pos!=-1) {
                buffer.push_front(s.substr(begin_pos, end_pos-begin_pos));// extract the sub-string before current delimiter
                if(end_pos != s.size()-1)
                    begin_pos = end_pos+delim.size();
                else
                    begin_pos = s.size();
                end_pos = s.find(delim, begin_pos);  // locate the next delimiter in string
            }
            if (begin_pos != s.size())
                buffer.push_front(s.substr(begin_pos, s.size()-begin_pos));  // extract the last sub-string
            deck.push_front(buffer);
            buffer.clear();
		}
    }

    while(deck.size()!=1){
    	t1 = orderi[0];
    	t2 = orderi[1];
    	int t = max(t1,t2);
    	for(i=0;i< t; i++ ){
    		if(i == t1-1)
    			deck1.push_front(deck[i]);
			else if(i == t2-1)
				deck2.push_front(deck[i]);
            else
                temp.push_back(deck[i]);

		}
        for(i=0;i< t; i++ ) deck.erase(deck.begin());  //erase the stacks you have pushed
        for(j=0;j< deck2[0].size();j++){
            if(deck2[0][j][0]==deck1[0][0][0]||deck2[0][j][1]==deck1[0][0][1]){
                deck1[0].push_front(deck2[0][j]);
                check = 1;          //check the last element of the deck2 at the top of the deck1;
            }
            else{
                deck1[0].push_back(deck2[0][j]);
                check = 0;
            }
        }
        deck2.clear();
        if(check==1){               //depends on the position of the last element of deck2 in the deck1
            deck.push_front(deck1[0]);
            for(i=0;i<temp.size();i++) deck.push_front(temp[i]);
        }
        else if(check ==0){
            for(i=0;i<temp.size();i++) deck.push_front(temp[i]);
            deck.push_front(deck1[0]);
        }
        deck1.clear();
        temp.clear();
		orderi.pop_front();
		orderi.pop_front();
    }
    ofstream output;
    output.open (argv[2]);
    for(i = 0; i<deck[0].size();i++) output << deck[0][i]<<" ";
    output.close();
    system("pause");
    return 0;
}
