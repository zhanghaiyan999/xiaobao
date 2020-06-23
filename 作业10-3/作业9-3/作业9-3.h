// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MY93_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MY93_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef MY93_EXPORTS
#define MY93_API __declspec(dllexport)
#else
#define MY93_API __declspec(dllimport)
#endif

// 此类是从 作业9-3.dll 导出的
class MY93_API C作业93 {
public:
	C作业93(void);
	// TODO:  在此添加您的方法。
};

extern MY93_API int n作业93;

MY93_API int fn作业93(void);
MY93_API int GetNum(int n);
MY93_API int Factorial(int n);
MY93_API float convert(float deg);

