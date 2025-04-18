/**
 * Created by LZX on 2021/09/13.
 */

/*******************************************************/
/*****************扩展类函数说明【A类，扩展类函数必须全部实现】************************/

/**********************************************************************
* 函数名称： // SDF_GenerateKeyPair_SM2
* 功能描述： // 生成SM2签名密钥对
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiIndex                签名密钥索引
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_GenerateKeyPair_SM2)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiIndex
);
#endif



/**********************************************************************
* 函数名称： // SDF_ImportKey
* 功能描述： // 导入明文会话密钥
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                pucKey                   缓冲区指针，用于存放输入的密钥
                puiKeyLength             输入的密钥密文长度
* 输出参数： // phKeyHandle              返回的密钥句柄
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ImportKey)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UCHAR *pucKey,
    SGD_UINT32 uiKeyLength,
    SGD_HANDLE *phKeyHandle
);
#endif


/**********************************************************************
* 函数名称： // SDF_ImportECCEncKeyPairWithISK_ECC
* 功能描述： // 密钥对保护结构导入用户加密密钥对
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiISKIndex             保护密钥对保护数据结构私钥索引
                uiImportIndex          导入用户加密密钥对索引
                pucECCKey,             密钥对保护数据结构
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_ImportECCEncKeyPairWithISK_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    SGD_UINT32 uiImportIndex,
    EnvelopedECCKey *pucECCKey,
);
#endif

/**********************************************************************
* 函数名称： // SDF_InternalDecrypt_ECC
* 功能描述： // 内部私钥ECC解密
* 输入参数： // phSessionHandle          与密码设备已建立的会话句柄
                uiISKIndex                   内部私钥索引
                pucEncData             输入密文数据
* 输出参数： // pucDataOutput              输出数据缓冲区
                puiOutputLength             输出数据明文长度
* 返 回 值： // 0                        成功
                非0                      失败，返回错误码
* 其它说明： //
***********************************************************************/
SDF_FUNCTION_INFO(SDF_InternalDecrypt_ECC)
#ifdef SD_NEED_ARG_LIST
(
    SGD_HANDLE hSessionHandle,
    SGD_UINT32 uiISKIndex,
    ECCCipher *pucEncData,
    SGD_UCHAR *pucDataOutput,
    SGD_UINT32 *puiOutputLength
);
#endif