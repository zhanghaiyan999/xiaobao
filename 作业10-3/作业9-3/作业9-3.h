// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MY93_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MY93_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MY93_EXPORTS
#define MY93_API __declspec(dllexport)
#else
#define MY93_API __declspec(dllimport)
#endif

// �����Ǵ� ��ҵ9-3.dll ������
class MY93_API C��ҵ93 {
public:
	C��ҵ93(void);
	// TODO:  �ڴ�������ķ�����
};

extern MY93_API int n��ҵ93;

MY93_API int fn��ҵ93(void);
MY93_API int GetNum(int n);
MY93_API int Factorial(int n);
MY93_API float convert(float deg);

