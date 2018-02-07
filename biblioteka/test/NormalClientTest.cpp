#include <boost/test/unit_test.hpp>
#include <NormalClient.h>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    NormalClient testowy;
    vector<unique_ptr<ClientType>> vec_typu;

    vec_typu.push_back(unique_ptr<ClientType>(new NormalClient()));
    BOOST_CHECK_EQUAL(vec_typu.at(0)->getDiscount(), 0);
}
