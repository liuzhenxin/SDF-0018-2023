/**
 * Created by LQQ on 2017/11/13.
 */


#ifndef _SDFT_H_
#define _SDFT_H_ 1


//errorCode
#include "sdfn.h"

/*常量定义*/
#define SGD_TRUE		0x00000001
#define SGD_FALSE		0x00000000


/*******************************************************************/
/*************************** 对称算法开始 **************************/
/*******************************************************************/
#define SGD_SM1                                 0x00000100
#define SGD_SM1_ECB                             0x00000101
#define SGD_SM1_CBC                             0x00000102
#define SGD_SM1_CFB                             0x00000104
#define SGD_SM1_OFB                             0x00000108
#define SGD_SM1_MAC                             0x00000110

#define SGD_SSF33                               0x00000200

#define SGD_SSF33_ECB                           0x00000201
#define SGD_SSF33_CBC                           0x00000202
#define SGD_SSF33_CFB                           0x00000204
#define SGD_SSF33_OFB                           0x00000208
#define SGD_SSF33_MAC                           0x00000210

#define SGD_SM4                                 0x00000400
#define SGD_SM4_ECB                             0x00000401
#define SGD_SM4_CBC                             0x00000402
#define SGD_SM4_CFB                             0x00000404
#define SGD_SM4_OFB                             0x00000408
#define SGD_SM4_MAC                             0x00000410

#define SGD_ZUC                                 0x00000800
#define SGD_ZUC_EEA3                            0x00000801
#define SGD_ZUC_EIA3                            0x00000802

#define SGD_DES                                 0x00001000
#define SGD_DES_ECB                             0x00001001
#define SGD_DES_CBC                             0x00001002
#define SGD_DES_CFB                             0x00001004
#define SGD_DES_OFB                             0x00001008
#define SGD_DES_MAC                             0x00001010

#define SGD_2DES                                0x00002000
#define SGD_2DES_ECB                            0x00002001
#define SGD_2DES_CBC                            0x00002002
#define SGD_2DES_CFB                            0x00002004
#define SGD_2DES_OFB                            0x00002008
#define SGD_2DES_MAC                            0x00002010

#define SGD_3DES                                0x00004000
#define SGD_3DES_ECB                            0x00004001
#define SGD_3DES_CBC                            0x00004002
#define SGD_3DES_CFB                            0x00004004
#define SGD_3DES_OFB                            0x00004008
#define SGD_3DES_MAC                            0x00004010

#define SGD_AES                                 0x00008000
#define SGD_AES_ECB                             0x00008001  //密钥长度128bit
#define SGD_AES_CBC                             0x00008002  //密钥长度128bit
#define SGD_AES_CFB                             0x00008004  //密钥长度128bit
#define SGD_AES_OFB                             0x00008008  //密钥长度128bit
#define SGD_AES_MAC                             0x00008010

#define SGD_AES192_ECB                          0x00010001  //密钥长度192bit
#define SGD_AES192_CBC                          0x00010002  //密钥长度192bit
#define SGD_AES192_CFB                          0x00010004  //密钥长度192bit
#define SGD_AES192_OFB                          0x00010008  //密钥长度192bit

#define SGD_AES256_ECB                          0x00020001  //密钥长度256bit
#define SGD_AES256_CBC                          0x00020002  //密钥长度256bit
#define SGD_AES256_CFB                          0x00020004  //密钥长度256bit
#define SGD_AES256_OFB                          0x00020008  //密钥长度256bit
/*******************************************************************/
/*************************** 对称算法结束 **************************/
/*******************************************************************/

/*******************************************************************/
/************************** 非对称算法开始 *************************/
/*******************************************************************/
#define SGD_RSA                                 0x00010000
#define SGD_RSA_SIGN                            0x00010100
#define SGD_RSA_ENC                             0x00010200
#define SGD_SM2                                 0x00020100
#define SGD_SM2_1                               0x00020200
#define SGD_SM2_2                               0x00020400
#define SGD_SM2_3                               0x00020800


#define SGD_ECC_secp256k1                       0x00000016
#define SGD_ECC_X9_62_prime256v1                0x00000017

/*******************************************************************/
/************************** 非对称算法结束 *************************/
/*******************************************************************/

/*******************************************************************/
/*************************** 杂凑算法开始 **************************/
/*******************************************************************/
#define SGD_SM3                                 0x00000001
#define SGD_SHA1                                0x00000002
#define SGD_SHA256                              0x00000004
#define SGD_SHA224                              0x00000010
#define SGD_SHA384                              0x00000011
#define SGD_SHA512                              0x00000012
#define SGD_MD5                                 0x00000014
/*******************************************************************/
/*************************** 杂凑算法结束 **************************/
/*******************************************************************/

/*******************************************************************/
/*************************** 数据类型定义开始 **************************/
/*******************************************************************/
typedef char				SGD_CHAR;
typedef char				SGD_INT8;
typedef short				SGD_INT16;
typedef int					SGD_INT32;
typedef long long			SGD_INT64;
typedef unsigned char		SGD_UCHAR;
typedef unsigned char		SGD_UINT8;
typedef unsigned short		SGD_UINT16;
typedef unsigned int		SGD_UINT32;
typedef unsigned long long	SGD_UINT64;
typedef unsigned int		SGD_RV;
typedef void*				SGD_OBJ;
typedef int					SGD_BOOL;
typedef void*				SGD_HANDLE;

typedef SGD_UCHAR           SGD_UTF8CHAR;
typedef SGD_UINT32          SGD_ULONG;

typedef SGD_UCHAR           SDF_PTR     SGD_BYTE_PTR;
typedef SGD_CHAR            SDF_PTR   SGD_CHAR_PTR;
typedef SGD_UCHAR           SDF_PTR  SGD_UCHAR_PTR;
typedef SGD_UTF8CHAR        SDF_PTR   SGD_UTF8CHAR_PTR;
typedef SGD_ULONG           SDF_PTR   SGD_ULONG_PTR;
typedef void                SDF_PTR   SGD_VOID_PTR;
/*******************************************************************/
/*************************** 数据类型定义结束 **************************/
/*******************************************************************/

/* SDF_FUNCTION_LIST is a structure holding a SKF spec
 * handle and pointers of appropriate types to all the
 * SKF functions
 */
typedef struct SDF_FUNCTION_LIST SDF_FUNCTION_LIST;

typedef SDF_FUNCTION_LIST SDF_PTR SDF_FUNCTION_LIST_PTR;

typedef SDF_FUNCTION_LIST_PTR SDF_PTR SDF_FUNCTION_LIST_PTR_PTR;

/*****************************************************************/

typedef struct DeviceInfo_st
{
    unsigned char IssuerName[40];
    unsigned char DeviceName[16];
    unsigned char DeviceSerial[16];
    unsigned int  DeviceVersion;
    unsigned int  StandardVersion;
    unsigned int  AsymAlgAbility[2];
    unsigned int  SymAlgAbility;
    unsigned int  HashAlgAbility;
    unsigned int  BufferSize;
}DEVICEINFO;

#define RSAref_MAX_BITS 2048
#define RSAref_MAX_LEN   ((RSAref_MAX_BITS+7)/8)
#define RSAref_MAX_PBITS ((RSAref_MAX_BITS+1)/2)
#define RSAref_MAX_PLEN ((RSAref_MAX_PBITS+7)/8)

typedef struct RSArefPublicKey_st
{
    unsigned int bits;//模长
    unsigned char m[RSAref_MAX_LEN];//摸N
    unsigned char e[RSAref_MAX_LEN];//公钥指数
}RSArefPublicKey;

typedef struct RSArefPrivateKey_st
{
    unsigned int bits;
    unsigned char m[RSAref_MAX_LEN];
    unsigned char e[RSAref_MAX_LEN];
    unsigned char d[RSAref_MAX_LEN];
    unsigned char prime[2][RSAref_MAX_PLEN];
    unsigned char pexp[2][RSAref_MAX_PLEN];
    unsigned char coef[RSAref_MAX_PLEN];
}RSArefPrivateKey;
//标准定义512
#define ECCref_MAX_BITS 512
//三未密定义256
//#define ECCref_MAX_BITS 256
#define ECCref_MAX_LEN ((ECCref_MAX_BITS+7)/8)

typedef struct ECCrefPublicKey_st
{
    unsigned int bits;
    unsigned char x[ECCref_MAX_LEN];
    unsigned char y[ECCref_MAX_LEN];
}ECCrefPublicKey;

typedef struct ECCrefPrivateKey_st
{
    unsigned int bits;//密钥位长
    unsigned char K[ECCref_MAX_LEN];//私钥
}ECCrefPrivateKey;

typedef struct ECCCipher_st
{
    unsigned char x[ECCref_MAX_LEN];
    unsigned char y[ECCref_MAX_LEN];
    unsigned char M[32];
    unsigned int L;
    unsigned char C[0];
}ECCCipher;

typedef struct ECCSignature_st
{
    unsigned char r[ECCref_MAX_LEN];
    unsigned char s[ECCref_MAX_LEN];
}ECCSignature;

//ECC加密密钥对保护结构
typedef struct EnvelopedECCKey_st{
unsigned int Version;                  // 版本号，本版本为1
unsigned int ulSymmAlgID;              // 对称算法标识，限定ECB模式
unsigned int ulBits;					// ECC密钥对的密钥位长
unsigned char  cbEncryptedPriKey[ECCref_MAX_LEN];  // ECC密钥对私钥的密文
ECCrefPublicKey PubKey;        // ECC密钥对的公钥
ECCCipher ECCCipherBlob;    // 用ECC保护公钥加密的对称密钥密文结构
}EnvelopedECCKey;


typedef struct DevVerInfo_st
{
    unsigned int    plVer;
    unsigned int    plTm;
    unsigned int    kernelVer;
    unsigned int    kernelTm;
    unsigned int    csmVer;
    unsigned int    reserved[11];
    unsigned int    sdkVer;
}DEVVERINFO;



#endif
