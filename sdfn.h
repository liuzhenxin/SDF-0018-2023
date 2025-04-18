/**
 * Created by LQQ on 2017/11/13.
 */

#ifndef _SDFN_H_
#define _SDFN_H_


/* Error codes for the SDF functions. */

/*******************************************************/
/*****************函数返回码说明************************/
/*******************************************************/
#define SDR_OK                                           0x00 //操作成功
#define SDR_BASE                                   0x01000000 //错误码基础值
#define SDR_UNKNOWERR                           SDR_BASE+0x01 //未知错误
#define SDR_NOTSUPPORT                          SDR_BASE+0x02 //不支持的接口类型
#define SDR_COMMFAIL                            SDR_BASE+0x03 //与设备通信失败
#define SDR_HARDFAIL                            SDR_BASE+0x04 //运算模块无响应
#define SDR_OPENDEVICE                          SDR_BASE+0x05 //打开设备失败
#define SDR_OPENSESSION                         SDR_BASE+0x06 //创建会话失败
#define SDR_PARDENY                             SDR_BASE+0x07 //无私钥使用权限
#define SDR_KEYNOTEXIST                         SDR_BASE+0x08 //不存在的密钥调用
#define SDR_ALGNOTSUPPORT                       SDR_BASE+0x09 //不支持的算法调用
#define SDR_ALGMODENOTSUPPORT                   SDR_BASE+0x0A //不支持的算法模式调用
#define SDR_PKOPERR                             SDR_BASE+0x0B //公钥运算失败
#define SDR_SKOPERR                             SDR_BASE+0x0C //私钥运算失败
#define SDR_SIGNERR                             SDR_BASE+0x0D //签名运算失败
#define SDR_VERIFYERR                           SDR_BASE+0x0E //验证签名失败
#define SDR_SYMOPERR                            SDR_BASE+0x0F //对称算法运算失败
#define SDR_STEPERR                             SDR_BASE+0x10 //多不运算错误
#define SDR_FILESIZEERR                         SDR_BASE+0x11 //文件长度超出限制
#define SDR_FILENOEXIST                         SDR_BASE+0x12 //指定的文件不存在
#define SDR_FILEOFSERR                          SDR_BASE+0x13 //文件其实位置错误
#define SDR_KEYTYPEERR                          SDR_BASE+0x14 //密钥类型错误
#define SDR_KEYERR                              SDR_BASE+0x15 //密钥错误
#define SDR_ENCDATAERR                          SDR_BASE+0x16 //ECC加密数据错误
#define SDR_RANDERR                             SDR_BASE+0x17 //随机数产生失败
#define SDR_PRKRERR                             SDR_BASE+0x18 //私钥使用权限获取失败
#define SDR_MACERR                              SDR_BASE+0x19 //MAC运算失败
#define SDR_FILEEXISTS                          SDR_BASE+0x1A //指定文件已存在
#define SDR_FILEWERR                            SDR_BASE+0x1B //文件写入失败
#define SDR_NOBUFFER                            SDR_BASE+0x1C //存储空间不足
#define SDR_INARGERR                            SDR_BASE+0x1D //输入参数错误
#define SDR_OUTARGERR                           SDR_BASE+0x1E //输出参数错误
#define SDR_USERIDERR                           SDR_BASE+0x1F //用户标识错误

//扩展错误码
#define SDR_TIMEOUT                             SDR_BASE+0x2F  //指令执行超时

#define SDR_ENC_DEC_DATA_LEN_ERR	            SDR_BASE+0x20  //加密/解密数据长度错误
#define SDR_IV_DATA_LEN_ERR			            SDR_BASE+0x21  //IV数据长度长度错误（不匹配算法）
#define SDR_KEY_LEN_ERR				            SDR_BASE+0x22  //密钥长度错误（不匹配算法）
#define SDR_CREATE_ECCKEY_ERR		            SDR_BASE+0x23  //密钥长度错误（不匹配算法）
#define SDR_ALLOC_MEM_FAILD			            SDR_BASE+0x24  //
#define SDR_SAVE_SSNKEY_FAILD		            SDR_BASE+0x25  //保存会话密钥失败
#define SDR_SSNKEY_INDEX_INVALID	            SDR_BASE+0x26  //会话密钥索引错误
#define SDR_CALC_SSNKEY_FAILED		            SDR_BASE+0x27  //计算会话密钥失败
#define SDR_ECDH_SSNKEY_FAILED		            SDR_BASE+0x28  //会话密钥协商失败

#define SDR_CONTINUE						    (SDR_BASE+0x40)


#endif /* _SDFN_H_ */
