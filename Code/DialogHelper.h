#include <windows.h>
#include <shobjidl.h> 
#include <string>
class DialogHelper
{
public:

    std::string userDefinedFilePath;
    std::string initialMsg = "Please ensure that the GameLevel.txt file is located in the same folder as the assets";

    std::string displayOpenFileDialogue() {
        
        PWSTR cmdArgs{};
        wWinMain(GetModuleHandle(NULL), 0, cmdArgs, 0);
        return userDefinedFilePath;
    }

    int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
    {
        HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
            COINIT_DISABLE_OLE1DDE);
        if (SUCCEEDED(hr))
        {
            
            std::wstring stemp = std::wstring(initialMsg.begin(), initialMsg.end());
            LPCWSTR sw = stemp.c_str();
            MessageBoxW(NULL, sw, L"File Path", MB_OK);
            IFileOpenDialog* pFileOpen;
            // Create the FileOpenDialog object.
            hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
                IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

            if (SUCCEEDED(hr))
            {
                // Show the Open dialog box.
                hr = pFileOpen->Show(NULL);

                // Get the file name from the dialog box.
                if (SUCCEEDED(hr))
                {
                    IShellItem* pItem;
                    hr = pFileOpen->GetResult(&pItem);
                    if (SUCCEEDED(hr))
                    {
                        PWSTR pszFilePath;
                        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                        // Display the file name to the user.
                        if (SUCCEEDED(hr))
                        {
                            MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
                            char str[256];
                            wcstombs(str, pszFilePath, 128);
                            userDefinedFilePath = std::string(str);
                            CoTaskMemFree(pszFilePath);
                        }
                        pItem->Release();
                    }
                }
                pFileOpen->Release();
            }
            CoUninitialize();
        }
        return 0;
    }
};

