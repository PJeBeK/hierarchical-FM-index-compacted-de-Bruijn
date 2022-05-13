// In this file we implement the rank and select
#include <iostream>
#include <math.h>
#include <sdsl/bit_vectors.hpp>
using namespace std;

struct rank_support
{
  sdsl::bit_vector b, rs, rb;
  uint64_t n, k, rs_width, rb_width;
  rank_support() {};
  
  rank_support(sdsl::bit_vector *b)
  {
    this->b = *b;
    init();
  }

  uint64_t operator () (uint64_t i)
  {
    return rank1(i);
  }

  void compute_lengths()
  {
    n = b.size();
    rs_width = k = ceil(log2(b.size()));
    rb_width = ceil(log2(k * k));
  }
  
  void init()
  {
    compute_lengths();
    uint64_t rs_len = rs_width * ceil(n / (k * k));
    uint64_t rb_len = rb_width * ceil(n / k);
    rs = sdsl::bit_vector(rs_len);
    rb = sdsl::bit_vector(rb_len);
    for (int i = 0; i*k*k < n; i ++)
      {
	write_on_rs(i, (i==0 ? 0 : read_from_rs(i - 1) + read_from_rb(i*k - 1) + count_ones_on_b(i*k*k - k, k)));
	for (int j = 0; j < k && i*k*k + j*k < n; j ++)
	  write_on_rb(i*k + j, (j==0 ? 0 : read_from_rb(i*k + j - 1) + count_ones_on_b(i*k*k + (j-1)*k, k)));
      }
  }

  uint64_t count_ones_on_b(uint64_t st, uint64_t len)
  {
    return __builtin_popcount(b.get_int(st, len));
  }
  
  uint64_t read_from_rs(uint64_t idx)
  {
    return rs.get_int(idx * rs_width, rs_width);
  }

  uint64_t read_from_rb(uint64_t idx)
  {
    return rb.get_int(idx * rb_width, rb_width);
  }

  void write_on_rs(uint64_t idx, uint64_t value)
  {
    rs.set_int(idx * rs_width, value, rs_width);
  }

  void write_on_rb(uint64_t idx, uint64_t value)
  {
    rb.set_int(idx * rb_width, value, rb_width);
  }
  
  uint64_t rank1(uint64_t i)
  {
    i ++;
    uint64_t rs_idx = i / (k * k);
    uint64_t rb_idx = i / k;
    return read_from_rs(rs_idx) + read_from_rb(rb_idx) + count_ones_on_b(i - (i % k), i % k);
  }

  uint64_t overhead()
  {
    uint64_t rs_len = rs_width * ceil(n / (k * k));
    uint64_t rb_len = rb_width * ceil(n / k);
    return rs_len + rb_len;
  }

  void save(string& fname)
  {
    ofstream fout(fname);
    b.serialize(fout);
    rs.serialize(fout);
    rb.serialize(fout);
  }

  void load(string& fname)
  {
    ifstream fin(fname);
    b.load(fin);
    rs.load(fin);
    rb.load(fin);
    compute_lengths();
  }
};

struct select_support
{
  rank_support *r;
  select_support() {};

  select_support(rank_support *r)
  {
    this->r = r;
  }

  uint64_t operator () (uint64_t i)
  {
    return select1(i);
  }
  
  uint64_t select1(uint64_t i)
  {
    int left = 0, right = r->n;
    while (left < right)
      {
	int mid = (left + right) / 2;
	if (r->rank1(mid) < i)
	  left = mid + 1;
	else
	  right = mid;
      }
    return left;
  }

  uint64_t overhead()
  {
    return r->overhead();
  }

  void save(string& fname)
  {
    r->save(fname);
  }

  void load(string& fname)
  {
    r->load(fname);
  }
};
