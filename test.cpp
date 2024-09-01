#include "./nda/vec.hpp"
#include "./nda/mat.hpp"
#include <iostream>
int main(){
    nda::vec<float> a = nda::vec<float>(2,1);
    nda::vec<float> b = nda::vec<float>(3,1) + a;
    nda::vec<float> c = nda::vec<float>(5,5);
    b = (5.0 + c + 2.0);
    std::cout<<b[0]<<" "<<b[1] << " "<<b[2] << " "<<b[3] << std::endl;
    b =  c;
    std::cout<<b[0]<<" "<<b[1] << " "<<b[2] << " "<<b[3] << std::endl;
    b.normalise();
    std::cout<<b[0]<<" "<<b[1] << " "<<b[2] << " "<<b[3] <<" "<<b.size()<< std::endl;
    std::cout<<b.l2norm()<<" "<<b.l1norm()<<std::endl;

    nda::vec<float> d = nda::vec<float>(3, 4);
    nda::mat<float> m1 = nda::mat<float>(5,3,1);
    nda::vec<float> e = m1 * d;
    std::cout<<e.size()<<": "<< e[0] << " " << e[1] << " " << e[2] << " " << e[3] << " " << e[4] << std::endl;

    nda::mat<float> id = nda::identity<float>(5);
    e = id * e;
    std::cout<<e.size()<<": "<< e[0] << " " << e[1] << " " << e[2] << " " << e[3] << " " << e[4] << std::endl;

    return 0;
}