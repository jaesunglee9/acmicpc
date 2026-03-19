#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int
main(void){
  ios::sync_with_stdio(false);cin.tie(0);

  unordered_set<string> us = {
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
  };

  int n; cin >> n; cin.ignore();
  bool allIn = true;
  for(int i = 0; i < n; i++) {
    string line; getline(cin, line);
    if (us.find(line) == us.end()) {
      allIn = false;
      break;
    }
  }

  if (allIn) cout << "No";
  else cout << "Yes";
  cout << '\n';

  return 0;
}

    

                             


  
