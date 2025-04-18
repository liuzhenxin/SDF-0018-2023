/**
 * Created by LZX on GM/T 0018-2023
 * 函数等级说明：
 * A类：必须实现
 * B类：有能力可实现，可暂时不实现
 * C类：不做要求，可不实现
 */

/*******************************************************/
/*****************6.2 设备管理类函数说明-【A类，设备管理类函数必须全部实现】************************/
/*******************************************************/
/**********************************************************************
* 函数名称： // SDF_OpenDevice
* 功能描述： // 打开设备
* 输入参数： //
* 输出参数： // phDeviceHandle       设备句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_OpenDevice)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE *phDeviceHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_CloseDevice
* 功能描述： // 关闭设备
* 输入参数： // phDeviceHandle       已打开的设备句柄
* 输出参数： //
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CloseDevice)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hDeviceHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_OpenSession
* 功能描述： // 创建会话
* 输入参数： // phDeviceHandle       已打开的设备句柄
* 输出参数： // phSessionHandle      返回与密码设备建立的新的会话句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_OpenSession)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hDeviceHandle,
    SGD_HANDLE *phSessionHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_CloseSession
* 功能描述： // 关闭会话
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
* 输出参数： //
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CloseSession)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GetDeviceInfo
* 功能描述： // 获取设备信息
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
* 输出参数： // pstDeviceInfo        设备能力描述信息
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GetDeviceInfo)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    DEVICEINFO *pstDeviceInfo

);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateRandom
* 功能描述： // 产生随机数
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiLength             欲获取的随机数长度
* 输出参数： // pucRandom            缓冲区指针，用于存放获取的随机数
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateRandom)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiLength,
    SGD_UCHAR *pucRandom
);
#endif
/**********************************************************************
* 函数名称： // SDF_GetPrivateKeyAccessRight
* 功能描述： // 获取私钥权限
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储私钥的索引值
                pucPassword          使用私钥权限的标识码
                uiPwdLength          私钥访问控制码长度，不少于8字节
* 输出参数： //
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GetPrivateKeyAccessRight)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiKeyIndex,
    SGD_UCHAR *pucPassword,
    SGD_UINT32  uiPwdLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_ReleasePrivateKeyAccessRight
* 功能描述： // 释放私钥权限
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储私钥的索引值
* 输出参数： //
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ReleasePrivateKeyAccessRight)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiKeyIndex
);
#endif
//
///*******************************************************/
///*****************6.3密钥管理类函数说明 【包含A类和B类，请关注其他说明，里面说明类别】 ************************/
///*******************************************************/
/**********************************************************************
* 函数名称： // SDF_ExportSignPublicKey_RSA
* 功能描述： // 导出密码设备内部存储的指定索引位置的RSA签名公钥
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储RSA密钥对的索引值
* 输出参数： // pucPublicKey         RSA公钥结构
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExportSignPublicKey_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiKeyIndex,
    RSArefPublicKey *pucPublicKey
);
#endif
/**********************************************************************
* 函数名称： // SDF_ExportEncPublicKey_RSA
* 功能描述： // 导出密码设备内部存储的指定索引位置的RSA加密公钥
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储RSA密钥对的索引值
* 输出参数： // pucPublicKey         RSA公钥结构
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExportEncPublicKey_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiKeyIndex,
    RSArefPublicKey *pucPublicKey
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithIPK_RSA
* 功能描述： // 生成会话密钥并用指定索引的内部加密公钥公钥加密输出，同时返回密钥句柄
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiIPKIndex           存储公钥的索引值
                uiKeyBits            指定产生的会话密钥长度
* 输出参数： // pucKey               缓冲区指针，用于存放返回的密钥密文
                puiKeyLength         返回的密钥密文的长度
                phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithIPK_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiIPKIndex,
    SGD_UINT32 uiKeyBits,
    SGD_UCHAR *pucKey,
    SGD_UINT32 *puiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithEPK_RSA
* 功能描述： // 生成会话密钥并用外部加密公钥公钥加密输出，同时返回密钥句柄
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyBits            指定产生的会话密钥长度
                pucPublicKey         输入的外部RSA公钥结构
* 输出参数： // pucKey               缓冲区指针，用于存放返回的密钥密文
                puiKeyLength         返回的密钥密文的长度
                phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithEPK_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiIPKIndex,
    SGD_UINT32 uiKeyBits,
    SGD_UCHAR *pucKey,
    SGD_UINT32 *puiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_ImportKeyWithISK_RSA
* 功能描述： // 导入会话密钥并用内部私钥解密，同时返回密钥句柄
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiISKIndex           加密私钥的索引值，对应于加密时的公钥
                pucKey               缓冲区指针，用于存放输入的密钥密文
                puiKeyLength         返回的密钥密文的长度
* 输出参数： // phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ImportKeyWithISK_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UCHAR *pucKey,
    SGD_UINT32 uiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_ExportSignPublicKey_ECC
* 功能描述： // 导出密码设备内部存储的指定索引位置的ECC签名公钥
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储ECC密钥对的索引值
* 输出参数： // pucPublicKey         ECC公钥结构
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExportSignPublicKey_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiKeyIndex,
    ECCrefPublicKey *pucPublicKey
);
#endif
/**********************************************************************
* 函数名称： // SDF_ExportEncPublicKey_ECC
* 功能描述： // 导出密码设备内部存储的指定索引位置的ECC加密公钥
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyIndex           存储ECC密钥对的索引值
* 输出参数： // pucPublicKey         ECC公钥结构
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExportEncPublicKey_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32  uiKeyIndex,
    ECCrefPublicKey *pucPublicKey
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithIPK_ECC
* 功能描述： // 生成会话密钥并用内部ECC公钥加密输出
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiIPKIndex           存储公钥的索引值
                uiKeyBits            指定产生的会话密钥长度
* 输出参数： // pucKey               缓冲区指针，用于存放返回的密钥密文
                phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithIPK_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiIPKIndex,
    SGD_UINT32 uiKeyBits,
    ECCCipher *pucKey,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithEPK_ECC
* 功能描述： // 生成会话密钥并用外部ECC公钥加密输出
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiKeyBits            指定产生的会话密钥长度
                uiAlgID              外部ECC公钥的算法标识
                pucPublicKey         输入的外部ECC公钥结构
* 输出参数： // pucKey               缓冲区指针，用于存放返回的密钥密文
                phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithEPK_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiKeyBits,
    SGD_UINT32 uiAlgID,
    ECCrefPublicKey *pucPublicKey,
    ECCCipher *pucKey,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_ImportKeyWithISK_ECC
* 功能描述： // 导入会话密钥并用内部ECC私钥解密，同时返回密钥句柄
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiISKIndex           存储私钥的索引值，对应于加密时的公钥
                pucKey               缓冲区指针，用于存放输入的密钥密文
                pucPublicKey         输入的外部ECC公钥结构
* 输出参数： // phKeyHandle          返回的密钥句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ImportKeyWithISK_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    ECCCipher *pucKey,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateAgreementDataWithECC
* 功能描述： // 使用ECC密钥协商算法，为计算会话密钥而产生协商参数
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                uiISKIndex           存储私钥的索引值，对应于加密时的公钥
                uiKeyBits            要求协商的密钥长度
                pucSponsorID         参与密钥协商的发起方ID
                uiSponsorIDLength    发起方ID长度
* 输出参数： // pucSponsorPublicKey  发起方ECC公钥结构
                purSponsorTmpPublicKey发起方临时ECC公钥结构
                phAgreementHandle    协商句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类,协商的发起方首先调用本函数
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateAgreementDataWithECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UINT32 uiKeyBits,
    SGD_UCHAR *pucSponsorID,
    SGD_UINT32 uiSponsorIDLength,
    ECCrefPublicKey *pucSponsorPublicKey,
    ECCrefPublicKey *pucSponsorTmpPublicKey,
    SGD_HANDLE *phAgreementHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithECC
* 功能描述： // 使用ECC密钥协商算法，为计算会话密钥而产生协商参数
* 输入参数： // phSessionHandle      与密码设备已建立的会话句柄
                pucSponsorID         参与密钥协商的发起方ID
                uiSponsorIDLength    发起方ID长度
                pucResponsePublicKey     外部输入的响应方ECC公钥结构
                pucResponseTmpPublicKey  外部输入的响应方临时ECC公钥结构
                hAgreementHandle  协商句柄，用于计算协商密钥
* 输出参数： // phKeyHandle    返回的协商句柄
* 返 回 值： // 0                    成功
                非0                  失败，返回错误码
* 其它说明： // B类, 协商的发起方首先调用本函数
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucResponseID,
    SGD_UINT32 uiResponseIDLength,
    ECCrefPublicKey *pucResponsePublicKey,
    ECCrefPublicKey *pucResponseTmpPublicKey,
    SGD_HANDLE hAgreementHandle,
    SGD_HANDLE *phKeyHandle
);
#endif

/**********************************************************************
* 函数名称： // SDF_GenerateAgreementDataAndKeyWithECC
* 功能描述： // 使用ECC密钥协商算法，产生协商参数并计算会话密钥
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiISKIndex               私钥索引
                uiKeyBits                协商后输出的密钥长度
                pucResponseID            响应方ID值
                uiResponseIDLength       响应方ID长度
                pucSponsorID             发起方ID值
                uiSponsorIDLength        发起方ID长度
                pucSponsorPublicKey      外部输入的发起方ECC公钥结构
                pucSponsorTmpPublicKey   外部输入的发起方临时ECC公钥结构
* 输出参数： // pucResponsePublicKey     返回的响应方ECC公钥结构
                pucResponseTmpPublicKey  返回的响应方临时ECC公钥结构
                phKeyHandle              返回的密钥句柄
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类, 本函数有响应方调用
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateAgreementDataAndKeyWithECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UINT32 uiKeyBits,
    SGD_UCHAR *pucResponseID,
    SGD_UINT32 uiResponseIDLength,
    SGD_UCHAR *pucSponsorID,
    SGD_UINT32 uiSponsorIDLength,
    ECCrefPublicKey *pucSponsorPublicKey,
    ECCrefPublicKey *pucSponsorTmpPublicKey,
  	ECCrefPublicKey  *pucResponsePublicKey,
  	ECCrefPublicKey  *pucResponseTmpPublicKey,
  	SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_GenerateKeyWithKEK
* 功能描述： // 生成会话密钥并用密钥加密密钥加密输出
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiKeyBits                产生的会话密钥长度
                uiAlgID                  算法标识，指定对称加密算法
                uiKEKIndex               存储密钥加密密钥的索引值
* 输出参数： // pucKey                   缓冲区指针，用于存放返回的密钥密文
                puiKeyLength             返回的密钥密文长度
                phKeyHandle              返回的密钥句柄
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyWithKEK)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiKeyBits,
    SGD_UINT32 uiAlgID,
    SGD_UINT32 uiKEKIndex,
    SGD_UCHAR *pucKey,
    SGD_UINT32 *puiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_ImportKeyWithKEK
* 功能描述： // 导入会话密钥并用密钥加密密钥解密
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiAlgID                  算法标识，指定对称加密算法
                uiKEKIndex               存储密钥加密密钥的索引值
                pucKey                   缓冲区指针，用于存放输入的密钥密文
                puiKeyLength             输入的密钥密文长度
* 输出参数： // phKeyHandle              返回的密钥句柄
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ImportKeyWithKEK)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiAlgID,
    SGD_UINT32 uiKEKIndex,
    SGD_UCHAR *pucKey,
    SGD_UINT32 uiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif
/**********************************************************************
* 函数名称： // SDF_DestoryKey
* 功能描述： // 销毁会话密钥
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                phKeyHandle              返回的密钥句柄
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_DestroyKey)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle
);
#endif

///*******************************************************/
///*****************6.4非对称算法运算类函数说明************************/
///*******************************************************/
/**********************************************************************
* 函数名称： // SDF_ExternalPublicKeyOperation_RSA
* 功能描述： // 使用外部公钥对数据进行运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucPublicKey             外部RSA公钥结构
                pucDataInput             缓冲区指针，用于存放输入的数据
                uiInputLength            输入的数据长度
* 输出参数： // pucDataOutput            缓冲区指针，用于存放输出的数据
                puiOutputLength          输出的数据长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExternalPublicKeyOperation_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    RSArefPublicKey *pucPublicKey,
    SGD_UCHAR *pucDataInput,
    SGD_UINT32 uiInputLength,
    SGD_UCHAR *pucDataOutput,
    SGD_UINT32 *puiOutputLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_InternalPublicKeyOperation_RSA
* 功能描述： // 使用内部公钥对数据进行运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiKeyIndex               存储公钥的索引值
                pucDataInput             缓冲区指针，用于存放输入的数据
                uiInputLength            输入的数据长度
* 输出参数： // pucDataOutput            缓冲区指针，用于存放输出的数据
                puiOutputLength          输出的数据长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类 索引范围仅限于内部签名密钥对
***********************************************************************/
SDF_FUNCTION_INFO(SDF_InternalPublicKeyOperation_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiKeyIndex,
    SGD_UCHAR *pucDataInput,
    SGD_UINT32 uiInputLength,
    SGD_UCHAR *pucDataOutput,
  	SGD_UINT32 *puiOutputLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_InternalPrivateKeyOperation_RSA
* 功能描述： // 使用内部私钥对数据进行运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiKeyIndex               存储私钥的索引值
                pucDataInput             缓冲区指针，用于存放输入的数据
                uiInputLength            输入的数据长度
* 输出参数： // pucDataOutput            缓冲区指针，用于存放输出的数据
                puiOutputLength          输出的数据长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类 索引范围仅限于内部签名密钥对
***********************************************************************/
SDF_FUNCTION_INFO(SDF_InternalPrivateKeyOperation_RSA)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiKeyIndex,
    SGD_UCHAR *pucDataInput,
    SGD_UINT32 uiInputLength,
    SGD_UCHAR *pucDataOutput,
  	SGD_UINT32 *puiOutputLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_ExternalVerify_ECC
* 功能描述： // 使用外部ECC公钥对ECC签名值进行验证
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiAlgID                  外部ECC算法标识
                pucPublicKey             外部ECC公钥结构
                pucDataInput             缓冲区指针，用于存放输入的数据
                uiInputLength            输入的数据长度
                pucSignature             缓冲区指针，用于存放输入的签名值数据
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExternalVerify_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiAlgID,
    ECCrefPublicKey *pucPublicKey,
    SGD_UCHAR *pucDataInput,
    SGD_UINT32 uiInputLength,
    ECCSignature *pucSignature
);
#endif
/**********************************************************************
* 函数名称： // SDF_InternalSign_ECC
* 功能描述： // 使用内部ECC私钥对数据进行签名运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiISKIndex               内部ECC签名私钥索引
                pucData                  缓冲区指针，用于存放输入的数据
                uiDataLength             输入的数据长度
* 输出参数： // pucSignature             缓冲区指针，用于存放输出的签名值数据
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_InternalSign_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UCHAR *pucData,
    SGD_UINT32
    uiDataLength,
    ECCSignature *pucSignature
);
#endif
/**********************************************************************
* 函数名称： // SDF_InternalVerify_ECC
* 功能描述： // 使用内部ECC公钥对ECC签名值进行验证
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiISKIndex               内部ECC签名私钥索引
                pucData                  缓冲区指针，用于存放输入的数据
                uiDataLength             输入的数据长度
                pucSignature             缓冲区指针，用于存放输入的签名值数据
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_InternalVerify_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    ECCSignature *pucSignature
);
#endif
/**********************************************************************
* 函数名称： // SDF_ExternalEncrypt_ECC
* 功能描述： // 使用外部ECC公钥对数据进行加密运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiAlgID                  ECC算法标志
                pucPublicKey             外部ECC公钥结构
                pucData                  缓冲区指针，用于存放输入的数据
                uiDataLength             输入的数据长度
* 输出参数： // pucEncData               缓冲区指针，用于存放输出的数据密文
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ExternalEncrypt_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiAlgID,
    ECCrefPublicKey *pucPublicKey,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    ECCCipher *pucEncData
);
#endif

///*******************************************************/
///*****************6.5对称密码运算函数说明************************/
///*******************************************************/

/**********************************************************************
* 函数名称： // SDF_Encrypt
* 功能描述： // 使用密钥句柄和IV数据对数据进行对称加密
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                      算法标志，指定对称加密算法
                pucIV                        缓冲区指针，存放输入和返回的IV数据
                pucData                    缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： // pucEncData               缓冲区指针，用于存放输出的数据密文
                   puiEncDataLength         输出的数据密文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // A类 函数不对数据进行填充，输入的数据必须是指定算法分组长度的整数倍
***********************************************************************/
SDF_FUNCTION_INFO(SDF_Encrypt)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 *puiEncDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_Decrypt
* 功能描述： // 使用密钥句柄和IV数据对数据进行对称解密
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定对称加密算法
                pucIV                    缓冲区指针，存放输入和返回的IV数据
                pucEncData               缓冲区指针，用于存放输入的数据密文
                uiEncDataLength          输入的数据密文长度
* 输出参数： // pucData                  缓冲区指针，用于存放输出的数据明文
                puiDataLength            输出的数据明文长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_Decrypt)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 uiEncDataLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 *puiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_CalculateMAC
* 功能描述： // 使用密钥句柄和IV数据对数据进行MAC运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定MAC加密算法
                pucIV                    缓冲区指针，存放输入和返回的IV数据
                pucData                  缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： // pucMAC                   缓冲区指针，用于存放输出的MAC值
                puiMACLength             输出的MAC值长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // B类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CalculateMAC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucMAC,
    SGD_UINT32 *puiMACLength
);
#endif

/**********************************************************************
* 函数名称： // SDF_AuthEnc
* 功能描述： // 使用密钥句柄对数据进行可鉴别加密运算。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定MAC加密算法
                pucStartVar              缓冲区指针，用于存放输入的开始变量S
                uiStartVarLength         输入的开始变量长度
                pucAad                   缓冲区指针，用于存放输入的额外的可鉴别数据
                uiAadLength              输入的额外的可鉴别数据长度
                pucData                  缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： // pucEncData                 缓冲区指针，用于存放输出的数据密文
                puiEncDataLength             输出的数据密文长度
*               pucAuthData                 缓冲区指针，用于存放输出的鉴别数据
                puiAuthDataLength             输出的鉴别数据长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // C类 此函数应用于可鉴别加密的CCM和GCM模式，输入输出数据应根据GM/T 0006定义的算法标识并按照GB/T 36624的规定进行确定
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthEnc)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucStartVar,
    SGD_UNIT32 uiStartVarLength,
    SGD_UCHAR *pucAad,
    SGD_UINT32 uiAadLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 *puiEncDataLength,
    SGD_UCHAR *pucAuthData,
    SGD_UINT32 *puiAuthDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_AuthDec
* 功能描述： // 使用密钥句柄对数据进行可鉴别解密运算。此函数应用于可鉴别加密的CCM和
              GCM模式，输入输出数据应根据GM/T 0006定义的算法标识并按照
              GB/T 36624的规定进行确定
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定MAC加密算法
                pucStartVar              缓冲区指针，用于存放输入的开始变量S
                uiStartVarLength         输入的开始变量长度
                pucAad                   缓冲区指针，用于存放输入的额外的可鉴别数据
                uiAadLength              输入的额外的可鉴别数据长度
*               pucAuthData                 缓冲区指针，用于存放输出的鉴别数据
                uiAuthDataLength             输出的鉴别数据长度
                pucEncData                  缓冲区指针，用于存放输入的数据密文
                uiEncDataLength             输入的数据密文长度
* 输出参数： // pucData                 缓冲区指针，用于存放输出的数据明文
                puiDataLength             输出的数据明文文长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // C类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthDec)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucStartVar,
    SGD_UNIT32 uiStartVarLength,
    SGD_UCHAR *pucAad,
    SGD_UINT32 uiAadLength,
    SGD_UCHAR *pucAuthData,
    SGD_UINT32 uiAuthDataLength
    SGD_UCHAR *pucEncData,
    SGD_UINT32 uiEncDataLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 puiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_EncryptInit
* 功能描述： // 多包数据加密初始化，设置加密密钥句柄、IV和算法标识
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                      算法标志，指定对称加密算法
                pucIV                        缓冲区指针，存放输入的IV数据
                uiIVLength             输入的IV数据长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_EncryptInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UINT32 uiIVLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_EncryptUpdate
* 功能描述： // 对多包数据进行对称加密运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucData                    缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： // pucEncData               缓冲区指针，用于存放输出的数据密文
                puiEncDataLength         输出的数据密文长度
* 返 回 值： // 0                        成功
* 其它说明： // C类 此函数不对数据进行填充出来。
***********************************************************************/
SDF_FUNCTION_INFO(SDF_EncryptUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 *puiEncDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_EncryptFinal
* 功能描述： // 多包数据加密结束，释放相关资源。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucLastEncData               缓冲区指针，用于存放输出的最后部分数据密文
                puiLastEncDataLength         输出的最后部分数据密文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 输出的最后部分密文可以为空
***********************************************************************/
SDF_FUNCTION_INFO(SDF_EncryptFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucLastEncData,
    SGD_UINT32 *puiLastEncDataLength
);
#endif

/**********************************************************************
* 函数名称： // SDF_DecryptInit
* 功能描述： // 多包数据解密初始化，设置解密密钥句柄、IV和算法标识
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle             指定的密钥句柄
                uiAlgID                算法标志，指定分组密码算法和工作模式
                pucIV                        缓冲区指针，存放输入的IV数据
                uiIVLength             输入的IV数据长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_DecryptInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UINT32 uiIVLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_DecryptUpdate
* 功能描述： // 对多包数据进行对称解密运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucEncData              缓冲区指针，用于存放输入的数据密文
                uiEncDataLength         输入的数据密文长度
* 输出参数： // pucData               缓冲区指针，用于存放输出的数据明文
                puiDataLength         输出的数据明文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 此函数不对数据进行填充出来。
***********************************************************************/
SDF_FUNCTION_INFO(SDF_DecryptUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 uiEncDataLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 *puiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_DecryptFinal
* 功能描述： // 多包数据解密结束，释放相关资源。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucLastData               缓冲区指针，用于存放输出的最后部分数据明文
                puiLastDataLength         输出的最后部分数据明文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 输出的最后部分明文可以为空
***********************************************************************/
SDF_FUNCTION_INFO(SDF_DecryptFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucLastData,
    SGD_UINT32 *puiLastDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_CalculateMACInit
* 功能描述： // 多包对称MAC初始化，设置MAC密钥句柄、IV和算法标识
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                      算法标志，指定对称加密算法
                pucIV                        缓冲区指针，存放输入的IV数据
                uiIVLength             输入的IV数据长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 对称MAC算法标识的约定同分组密码算法
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CalculateMACInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucIV,
    SGD_UINT32 uiIVLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_CalculateMACUpdate
* 功能描述： // 对多包数据进行对称MAC运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucData                    缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 此函数不对数据进行填充出来。
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CalculateMACUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_CalculateMACFinal
* 功能描述： // 多包数据MAC结束，返回MAC计算结果，释放相关资源。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucMac               缓冲区指针，用于存放输出的MAC值
                puiMacLength         输出的MAC值长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_CalculateMACFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucMac,
    SGD_UINT32 *puiMacLength
);
#endif

/**********************************************************************
* 函数名称： // SDF_AuthEncInit
* 功能描述： // 多包数据可鉴别加密初始化，设置密钥句柄、算法标识、开始变量、额外的可鉴别数据。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定MAC加密算法
                pucStartVar              缓冲区指针，用于存放输入的开始变量S
                uiStartVarLength         输入的开始变量长度
                pucAad                   缓冲区指针，用于存放输入的额外的可鉴别数据
                uiAadLength              输入的额外的可鉴别数据长度
                pucData                  缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // C类 此函数应用于可鉴别加密的CCM和GCM模式，输入输出数据应根据GM/T 0006定义的算法标识并按照GB/T 36624的规定进行确定
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthEncInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucStartVar,
    SGD_UNIT32 uiStartVarLength,
    SGD_UCHAR *pucAad,
    SGD_UINT32 uiAadLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 *puiEncDataLength,
    SGD_UCHAR *pucAuthData,
    SGD_UINT32 *puiAuthDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_AuthEncUpdate
* 功能描述： // 对多包数据进行可鉴别加密运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucData                    缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： // pucEncData               缓冲区指针，用于存放输出的数据密文
                puiEncDataLength         输出的数据密文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 此函数的输出不包括鉴别数据。
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthEncUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 *puiEncDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_AuthEncFinal
* 功能描述： // 多包数据可鉴别加密结束，释放相关资源。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucLastEncData               缓冲区指针，用于存放输出的最后部分数据密文
                puiLastEncDataLength         输出的最后部分数据密文长度
           //   pucAuthData                 缓冲区指针，用于存放输出的鉴别数据
           //   puiAuthDataLength             输出的鉴别数据长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 输出的最后部分密文可以为空
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthEncFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucLastEncData,
    SGD_UINT32 *puiLastEncDataLength,
    SGD_UCHAR *pucAuthData,
    SGD_UINT32 *puiAuthDataLength
);
#endif

/**********************************************************************
* 函数名称： // SDF_AuthDecInit
* 功能描述： // 多包数据可鉴别解密初始化，设置密钥句柄、算法标识、开始变量、额外的可鉴别数据。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  算法标志，指定MAC加密算法
                pucStartVar              缓冲区指针，用于存放输入的开始变量S
                uiStartVarLength         输入的开始变量长度
                pucAad                   缓冲区指针，用于存放输入的额外的可鉴别数据
                uiAadLength              输入的额外的可鉴别数据长度
*               pucAuthData                 缓冲区指针，用于存放输出的鉴别数据
                uiAuthDataLength             输出的鉴别数据长度
                uiDataLength             输入的数据明文总长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // C类 此函数应用于可鉴别加密的CCM和GCM模式，输入输出数据应根据GM/T 0006定义的算法标识并按照GB/T 36624的规定进行确定
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthDecInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID,
    SGD_UCHAR *pucStartVar,
    SGD_UNIT32 uiStartVarLength,
    SGD_UCHAR *pucAad,
    SGD_UINT32 uiAadLength,
    SGD_UCHAR *pucAuthData,
    SGD_UINT32 uiAuthDataLength
    SGD_UCHAR *pucEncData,
    SGD_UINT32 uiEncDataLength,
    SGD_UINT32 uiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_AuthDecUpdate
* 功能描述： // 对多包数据进行可鉴别解密运算
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucEncData              缓冲区指针，用于存放输入的数据密文
                uiEncDataLength         输入的数据密文长度
* 输出参数： // pucData               缓冲区指针，用于存放输出的数据明文
                puiDataLength         输出的数据明文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 此函数不对数据进行填充出来。
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthDecUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucEncData,
    SGD_UINT32 uiEncDataLength,
    SGD_UCHAR *pucData,
    SGD_UINT32 *puiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_AuthDecFinal
* 功能描述： // 多包数据可鉴别解密结束，释放相关资源。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucLastData               缓冲区指针，用于存放输出的最后部分数据明文
                puiLastDataLength         输出的最后部分数据明文长度
* 返 回 值： // 0                        成功
                    非0                      失败，返回错误码
* 其它说明： // C类 输出的最后部分明文可以为空
***********************************************************************/
SDF_FUNCTION_INFO(SDF_AuthDecFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucLastData,
    SGD_UINT32 *puiLastDataLength
);
#endif
///*******************************************************/
///*****************杂凑运算函数说明************************/
///*******************************************************/
/**********************************************************************
* 函数名称： // SDF_HMACInit
* 功能描述： // 三部式带密钥的数据杂凑运算第一步。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                hKeyHandle               指定的密钥句柄
                uiAlgID                  指定杂凑算法标志
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类 本函数执行带密钥的杂凑运算过程应符合GB/T 15852.2
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HMACInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandle,
    SGD_UINT32 uiAlgID
);
#endif
/**********************************************************************
* 函数名称： // SDF_HMACUpdate
* 功能描述： // 三部式带密钥的数据杂凑运算第二步，对输入的明文进行杂凑运算。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucData                  缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类 本函数执行带密钥的杂凑运算过程应符合GB/T 15852.2
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HMACUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_HMACFinal
* 功能描述： // 三部式带密钥的数据杂凑运算第三步，杂凑运算结束返回杂凑数据并清除中间数据。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucHMac                  缓冲区数据，用于存放输出的杂凑数据
                puiHMacLength           返回杂凑数据的长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类 本函数执行带密钥的杂凑运算过程应符合GB/T 15852.2
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HMACFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucHMac,
    SGD_UINT32 *puiHMacLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_HashInit
* 功能描述： // 三部式杂凑运算第一步
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiAlgID                  指定杂凑算法标志
                pucPublicKey             签名者公钥，当uiAlgID为SGD_SM3时有效
                pucID                    签名者ID，当uiAlgID为SGD_SM3时有效
                uiIDLength               签名者ID长度，当uiAlgID为SGD_SM3时有效
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类 uiIDLength非零且uiAlgID为SGD_SM3时，本函数执行的是SM2的预处理1操作，此时pubPublicKey不能为空，SM2算法预处理过程应符合GB/T 35276
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HashInit)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiAlgID,
    ECCrefPublicKey *pucPublicKey,
    SGD_UCHAR *pucID,
    SGD_UINT32 uiIDLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_HashUpdate
* 功能描述： // 三部式杂凑运算第二步,对输入的明文进行杂凑运算。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucData                  缓冲区指针，用于存放输入的数据明文
                uiDataLength             输入的数据明文长度
* 输出参数： //
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HashUpdate)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucData,
    SGD_UINT32 uiDataLength
);
#endif
/**********************************************************************
* 函数名称： // SDF_HashFinal
* 功能描述： // 三部式杂凑运算第三步，杂凑运算结束返回杂凑数据并清除中间数据。
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
* 输出参数： // pucHash                  缓冲区数据，用于存放输出的杂凑数据
                puiHashLength           返回杂凑数据的长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： // A类
***********************************************************************/
SDF_FUNCTION_INFO(SDF_HashFinal)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucHash,
    SGD_UINT32 *puiHashLength
);
#endif
///*******************************************************/
///*****************用户文件操作函数说明【A类，文件操作类函数必须全部实现】************************/
///*******************************************************/
///**********************************************************************
//* 函数名称： // SDF_CreateFile
//* 功能描述： // 在密码设备内部创建文件
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                pucFileName              缓冲区指针，用于存放输入的文件名，最大128字节
//                uiNameLen                文件名长度
//                uiFileSize               文件所占存储空间的长度
//* 输出参数： //
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： //
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_CreateFile)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucFileName,
    SGD_UINT32 uiNameLen,
    SGD_UINT32 uiFileSize
);
#endif
///**********************************************************************
//* 函数名称： // SDF_ReadFile
//* 功能描述： // 在密码设备内部读取文件
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                pucFileName              缓冲区指针，用于存放输入的文件名，最大128字节
//                uiNameLen                文件名长度
//                uiOffset                 读取文件时的偏移量
//                puiFileLength            入参时指定读取文件的长度，出参时返回实际读取的长度
//* 输出参数： // pucBuffer                缓冲区指针，用于存放读取的文件数据
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： //
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_ReadFile)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucFileName,
    SGD_UINT32 uiNameLen,
    SGD_UINT32 uiOffset,
    SGD_UINT32 *puiReadLength,
    SGD_UCHAR *pucBuffer
);
#endif
///**********************************************************************
//* 函数名称： // SDF_WriteFile
//* 功能描述： // 在密码设备内部写入文件
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                pucFileName              缓冲区指针，用于存放输入的文件名，最大128字节
//                uiNameLen                文件名长度
//                uiOffset                 写文件时的偏移量
//                uiFileLength             指定写文件的长度
//                pucBuffer                缓冲区指针，用于存放输入的写文件数据
//* 输出参数： //
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： //
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_WriteFile)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucFileName,
    SGD_UINT32 uiNameLen,
    SGD_UINT32 uiOffset,
    SGD_UINT32 uiWriteLength,
    SGD_UCHAR *pucBuffer
);
#endif
///**********************************************************************
//* 函数名称： // SDF_DeleteFile
//* 功能描述： // 在密码设备内部删除指定文件
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                pucFileName              缓冲区指针，用于存放输入的文件名，最大128字节
//                uiNameLen                文件名长度
//* 输出参数： //
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： //
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_DeleteFile)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucFileName,
    SGD_UINT32 uiNameLen
);
#endif
///*******************************************************/
///*****************VPN设备相关接口函数说明【B类：有能力可实现，可暂时不实现】************************/
///*******************************************************/
///**********************************************************************
//* 函数名称： // SDF_GenerateKeywithSSL
//* 功能描述： // 使用SSL握手协议得到的密钥计算参数计算SSL工作密钥，同时返回工作密钥句柄。
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                hKeyHandlePreMaster     预主密钥pre_master_secret密钥句柄
//                pucClientRandom         客户端随机数
//                uiClientRandomLength    客户端随机数长度
//                pucServerRandom         服务端随机数
//                uiServerRandomLength    服务端随机数长度
//                uiPrfAlgID              PRF算法标识
//                uiKeyBitsClientMac      客户端杂凑密钥长度
//                uiKeyBitsServerMac      服务端杂凑密钥长度
//                uiKeyBitsClientEnc      客户端加密密钥长度
//                uiKeyBitsServerEnc      服务端加密密钥长度
//                uiClientIVLength        客户端IV长度
//                uiServerIVLength        服务端IV长度
//* 输出参数： // phKeyHandleClientMac      返回客户端杂凑密钥句柄
//              phKeyHandleServerMac      返回服务端杂凑密钥句柄
//              phKeyHandleClientEnc      返回客户端加密密钥句柄
//              phKeyHandleServerEnc      返回服务端加密密钥句柄
//              pucClientIV               缓冲区指针，用于存放返回的客户端IV
//              pucServerIV               缓冲区指针，用于存放返回的服务端IV
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： // SSL计算工作密钥的过程符合GM/T 0024。SSL握手协议消息交互完成后，本函数由参与通信的双方各自调用，计算SSL记录层协议的工作密钥并返回密钥句柄。
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeywithSSL)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandlePreMaster,
    SGD_UCHAR *pucClientRandom,
    SGD_UINT32 uiClientRandomLength,
    SGD_UCHAR *pucServerRandom,
    SGD_UINT32 uiServerRandomLength,
    SGD_UINT32 uiPrfAlgID,
    SGD_HANDLE *phKeyHandleClientMac,
    SGD_UINT32 uiKeyBitsClientMac,
    SGD_HANDLE *phKeyHandleServerMac,
    SGD_UINT32 uiKeyBitsServerMac,
    SGD_HANDLE *phKeyHandleClientEnc,
    SGD_UINT32 uiKeyBitsClientEnc,
    SGD_HANDLE *phKeyHandleServerEnc,
    SGD_UINT32 uiKeyBitsServerEnc,
    SGD_UCHAR *pucClientIV,
    SGD_UINT32 uiClientIVLength,
    SGD_UCHAR *pucServerIV,
    SGD_UINT32 uiServerIVLength
);
#endif
///**********************************************************************
//* 函数名称： // SDF_GenerateKeywithEPK_SSL
//* 功能描述： // 使用SS:握手协议得到的密钥计算参数计算SSL工作密钥，并用外部ECC公钥加密输出。
//* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
//                hKeyHandlePreMaster     预主密钥pre_master_secret密钥句柄
//                pucClientRandom         客户端随机数
//                uiClientRandomLength    客户端随机数长度
//                pucServerRandom         服务端随机数
//                uiServerRandomLength    服务端随机数长度
//                uiPrfAlgID              PRF算法标识
//                uiEccAlgID              外部ECC公钥的算法标识
//                pucPublicKey            输入的外部ECC公钥结构
//                uiKeyBitsClientMac      客户端杂凑密钥长度
//                uiKeyBitsServerMac      服务端杂凑密钥长度
//                uiKeyBitsClientEnc      客户端加密密钥长度
//                uiKeyBitsServerEnc      服务端加密密钥长度
//                uiClientIVLength        客户端IV长度
//                uiServerIVLength        服务端IV长度
//* 输出参数： // pucKeyClientMac           缓冲区指针，用于存放返回的客户端杂凑密钥
//              pucKeyServerMac           缓冲区指针，用于存放返回的服务端杂凑密钥
//              pucKeyClientEnc           缓冲区指针，用于存放返回的客户端加密密钥
//              pucKeyServerEnc           缓冲区指针，用于存放返回的服务端加密密钥
//              pucClientIV               缓冲区指针，用于存放返回的客户端IV
//              pucServerIV               缓冲区指针，用于存放返回的服务端IV
//* 返 回 值： // 0                        成功
//                非0                      失败，返回错误码
//* 其它说明： // SSL计算工作密钥的过程符合GM/T 0024。SSL握手协议消息交互完成后，本函数由参与通信的双方各自调用，计算SSL记录层协议的工作密钥并返回密钥句柄。
//***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeywithEPK_SSL)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_HANDLE hKeyHandlePreMaster,
    SGD_UCHAR *pucClientRandom,
    SGD_UINT32 uiClientRandomLength,
    SGD_UCHAR *pucServerRandom,
    SGD_UINT32 uiServerRandomLength,
    SGD_UINT32 uiPrfAlgID,
    SGD_UINT32 uiEccAlgID,
    ECCrefPublicKey *pucPublicKey,
    ECCCipher *pucKeyClientMac,
    SGD_UINT32 uiKeyBitsClientMac,
    ECCCipher *pucKeyServerMac,
    SGD_UINT32 uiKeyBitsServerMac,
    ECCCipher *pucKeyClientEnc,
    SGD_UINT32 uiKeyBitsClientEnc,
    ECCCipher *pucKeyServerEnc,
    SGD_UINT32 uiKeyBitsServerEnc,
    SGD_UCHAR *pucClientIV,
    SGD_UINT32 uiClientIVLength,
    SGD_UCHAR *pucServerIV,
    SGD_UINT32 uiServerIVLength
);
#endif
