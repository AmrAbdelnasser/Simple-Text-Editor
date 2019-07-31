#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string S;
    string W;
    vector<string> tmpS;
    string tmpS_sinlgeuse;
    int k;
    int Q;
    vector<int> len_added;
    int len_added_single;
    cin>>Q;
    int op;
    vector<int> prev_op;
    while (Q>0)
    {
        cin>>op;
        if(op==1) // Append string W to the end of S.
        {
            cin>>W;
            S+=W;
            len_added.push_back(W.size());
            prev_op.push_back(op);
        }
        else if(op==2) //Delete the last k characters of S.
        {
            cin>>k;
            tmpS.push_back(S.substr((S.size()-k), k));
            S.erase((S.size()-k), k);
            prev_op.push_back(op);
        }
        else if(op==3) //Print the kth character of S.
        {
            cin>>k;
            cout<<S[k-1]<<endl;
        }
        else if(op==4) //Undo the last (not previously undone) operation of type 1 or 2, reverting  to the state it was in prior to that operation.
        {
            if (*(prev_op.end()-1) == 1)
            {
                prev_op.pop_back();
                len_added_single = *(len_added.end()-1);
                len_added.pop_back();
                S.erase((S.size()-len_added_single), len_added_single);
            }
            else if (*(prev_op.end()-1) == 2)
            {
                prev_op.pop_back();
                tmpS_sinlgeuse = *(tmpS.end()-1);
                tmpS.pop_back();
                S.append(tmpS_sinlgeuse);
                tmpS_sinlgeuse.clear();
            }
        }
        else if(op==5) //display whole word
        {
            cout<<S<<endl;
        }
        --Q;
    }

    return 0;
}
