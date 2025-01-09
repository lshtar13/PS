#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
class fio {
	size_t rsize;
	unsigned char* rbuf;
	int ridx;

public:
	fio() : ridx(0) {
		struct stat rstat;
		fstat(0, &rstat);
		rsize = rstat.st_size;
		rbuf = (unsigned char*)mmap(0, rsize, PROT_READ, MAP_FILE | MAP_PRIVATE, 0, 0);
	}

	inline bool isBlank() {
		return
			rbuf[ridx] == '\n' || rbuf[ridx] == '\t' || rbuf[ridx] == '\r' ||
			rbuf[ridx] == '\f' || rbuf[ridx] == '\v' || rbuf[ridx] == ' ';
	}
	inline void consumeBlank() { while (isBlank()) ridx++; }

	inline int readInt() {
		int res = 0, flag = 0;
		consumeBlank();
		if (rbuf[ridx] == '-') {
			flag = 1;
			ridx++;
		}
		while (!isBlank() && ridx < rsize)
			res = 10 * res + rbuf[ridx++] - '0';
		return flag ? -res : res;
	}
}input;

using namespace std;
typedef long long ll;

int m, n, mat[2*700-1] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n;
    for(int d0, d1, d2, i = 0; i<n; ++i)
    {
        cin>>d0>>d1>>d2;
        for(int l = 0; l<2*m-1; ++l)
        {
            if(l<d0)
            {
                mat[l] += 0;
            }
            else if(l<(d0+d1))
            {
                mat[l] += 1;
            }
            else
            {
                mat[l] += 2;
            }
        }
    }

    for(int i = m-1; i<2*m-1; ++i)
    {
        cout<<mat[i]+1<<" ";
    }
    cout<<"\n";

    for(int i = m-2; i>=0; --i)
    {
        cout<<mat[i]+1<<" ";
        for(int l = 0; l<m-1; ++l)
        {
            cout<<mat[m+l]+1<<" ";
        }
        cout<<"\n";
    }

    return 0;
}