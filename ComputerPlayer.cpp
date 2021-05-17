#include<map>
#include<string>
#include<vector>
#include "Model.h"
using namespace std;
class ComputerPlayer: public TicTacModel  {
	virtual void setPlayer1ID(){
		Player1ID='O';
	}
	virtual void setPlayer1Name(){
		Player1Name="COMPUTER";
	}
	virtual void doPlayer1Move() {
		map<int, int>  TicMap;
		map<int,int> TicReverse;
		TicMap[8]=0;
		TicMap[3]=1;
		TicMap[4]=2;
		TicMap[1]=3;
		TicMap[5]=4;
		TicMap[9]=5;
		TicMap[6]=6;
		TicMap[7]=7;
		TicMap[2]=8;
		TicReverse[0]=8;
		TicReverse[1]=3;
		TicReverse[2]=4;
		TicReverse[3]=1;
		TicReverse[4]=5;
		TicReverse[5]=9;
		TicReverse[6]=6;
		TicReverse[7]=7;
		TicReverse[8]=2;
		
		vector <int> computer;
		vector <int> player;
		for(int i=0;i<=8;i++){
			if(boardLayout[i]==Player1ID){
				computer.push_back(TicReverse[i]);
			}
			else if(boardLayout[i]==Player2ID){
				player.push_back(TicReverse[i]);
			}
			else{
			}
		}
		if(computer.size()<=1 and player.size()<=1){
			recordMove(findRandomBlock(),Player1ID);
			return;
		}
		else if(computer.size()<=1){
			for (int i=0;i<player.size();i++) {
				for(int j=i+1;j<player.size();j++){
					int temp=15-(player[i]+player[j]);
					int index=TicMap[temp];
					if(isCellEmpty(index)){
						recordMove(index,Player1ID);
						return;
					}
				}
			}
			recordMove(findRandomBlock(),Player1ID);
			return;
		}
		else{
			for (int i=0;i<computer.size();i++) {
				for(int j=i+1;j<computer.size();j++){
					int temp=15-(computer[i]+computer[j]);
					int index=TicMap[temp];
					if(isCellEmpty(index)){
						recordMove(index,Player1ID);
						return;
					}
				}
			}
			for (int i=0;i<player.size();i++) {
				for(int j=i+1;j<player.size();j++){
					int temp=15-(player[i]+player[j]);
					int index=TicMap[temp];
					if(isCellEmpty(index)){
						recordMove(index,Player1ID);
						return;
					}
				}
			}
			recordMove(findRandomBlock(),Player1ID);
			return;
		}
	}
};
			
		
				
		