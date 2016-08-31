// -*- mode: cpp -*-
// g++ main.cpp -lboost_unit_test_framework

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DecryptorTest
#include <boost/test/unit_test.hpp>
#include "rotor.h"
#include "funcs.h"
#include <string>

// The alphabet for comparing to the decryptor's output. 
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

/**
 * Test that a Rotor will decrypt letters correctly when using disk 1
 */
BOOST_AUTO_TEST_CASE(test_disk1)
{
  //Input string which should correspond to the alphabet. 
  const string input1 = "KBLCMDNEOFPGQHRISJTKULVMWN";
  //Select disk 1 for testing. 
  Rotor disk1(1);
  
  //Loop through each letter of the input string and ensure
  //that it corresponds to the correct letter of the alphabet.
  for (int x = 0; x < 26; x++){
    BOOST_CHECK_EQUAL(disk1.decrypt(input1[x]), alphabet[x]);
  }
}

/**
 * Test that a Rotor will decrypt letters correctly when using disk 2
 */
BOOST_AUTO_TEST_CASE(test_disk2)
{
  const string input2 = "WBXCYDZEAFBGCHDIEJFKGLHMIN";
  Rotor disk2(2);

  for (int x = 0; x < 26; x++){
    BOOST_CHECK_EQUAL(disk2.decrypt(input2[x]), alphabet[x]);
  }
}
/**
 * Test that a Rotor will decrypt letters correctly when using disk 3
 */
BOOST_AUTO_TEST_CASE(test_disk3)
{
  const string input3 = "WTNFDRGUIJYSHXPOWZPJSVKZUR";
  Rotor disk3(3);
  
  for (int x = 0; x < 26; x++){
    BOOST_CHECK_EQUAL(disk3.decrypt(input3[x]), alphabet[x]);
  }
}

/**
 * Test that a Rotor will decrypt letters correctly when using disk 4
 */
BOOST_AUTO_TEST_CASE(test_disk4)
{
  const string input4 = "BZEYHXKWNVQUTTWSZRCQFPIOLN";
  Rotor disk4(4);

  for (int x = 0; x < 26; x++){
    BOOST_CHECK_EQUAL(disk4.decrypt(input4[x]), alphabet[x]);
  }
}

/**
 * Test that a Rotor will decrypt letters correctly when using disk 5
 */
BOOST_AUTO_TEST_CASE(test_disk5)
{
  const string input5 = "AZEYDDCCHBGGFFKEJJIINHMMLL";
  Rotor disk5(5);

  for (int x = 0; x < 26; x++){
    BOOST_CHECK_EQUAL(disk5.decrypt(input5[x]), alphabet[x]);
  }
}

BOOST_AUTO_TEST_CASE(test_decrypt_message)
{
  //Complete encrypted messages and the resulting unencrypted message.
  string msg1 = "RTFNXL_JLOCUCGW_NAVGLHSTAR_RUYPEDYUR_SEFW_XELOBIDKB_VEFMKJKU_YVXJVG";
  string msg2 = "TLOYEH_WKGBZWMO_NQBMIVXURH_MDUQWIRLK_SQKO_OVHIYOHQP_ZGLVTHFT_BSAXKL";
  string answ = "ZAPDOS_SQUIRTLE_BUTTERFREE_POLIWHIRL_JYNX_TENTACOOL_MAGIKARP_VULPIX";

  //Ensures that messages decrypt to correct string.
  BOOST_CHECK_EQUAL(decrypt_message(1, 2, 3, msg1), answ);
  BOOST_CHECK_EQUAL(decrypt_message(2, 4, 5, msg2), answ);
}
