// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CLI_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CLI_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CLI_EXPORTS
#define CLI_API __declspec(dllexport)
#else
#define CLI_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CLI_API Ccli {
public:
	Ccli(void);
	// TODO: add your methods here.
};

extern CLI_API int ncli;

CLI_API int fncli(void);
