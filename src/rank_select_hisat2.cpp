// In this code we use rank_select.h to find unitig ID and relative position for output of HISAT2
#include "rank_select.h"
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fbit(argv[1]);
    ifstream findex(argv[2]);
    string bit_vector_string;
    fbit >> bit_vector_string;
    sdsl::bit_vector b(bit_vector_string.size(), 0);
    for(int i = 0; i < bit_vector_string.size(); i ++)
        if(bit_vector_string[i] == '1')
            b[i] = 1;

    rank_support r(&b);
    select_support s(&r);

    string tmp, query;
    getline(findex, tmp);
    getline(findex, tmp);
    getline(findex, tmp);
    while(findex >> tmp)
    {
        int place;
        findex >> tmp >> tmp >> place >> tmp >> tmp >> tmp >> tmp >> tmp >> query;
        getline(findex, tmp);
        int unitig_id = r(place);
        int unitig_rel_pos = place - s(unitig_id);
        cout << query << " : (" << unitig_id << ", " << unitig_rel_pos << ") ";
        cout<<endl;
    }
}
