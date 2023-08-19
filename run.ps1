function install-dependences 
{
    # download and install visual studio
    $visual_studio_download_url = "https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2414&workload=dotnetwebcloud&flight=FlipMacCodeCF;35d&installerFlight=FlipMacCodeCF;35d&passive=false#dotnet"
    $path = "."
    Invoke-WebRequest -URI $visual_studio_download_url -OutFile $path
    vs_installer.exe --installPath "C:\visual_studio" --add Microsoft.VisualStudio.Workload.NativeDesktop --add Microsoft.VisualStudio.Workload.ManagedDesktop

     
    # Install vcpkg, which is an open-source package manager for Windows.
    git clone https://github.com/microsoft/vcpkg
    .\vcpkg\bootstrap-vcpkg.bat
    .\vcpkg\vcpkg.exe install raylib:x64-windows


}

function build
{
    $folderName = "build"

    if (Test-Path $folderName) {
        Write-Host "Folder $folderName already exists."
        Build2
    } else {
        Write-Host "Folder $folderName does not exist. Creating..."
        New-Item -ItemType Directory -Name $folderName
        Write-Host "Folder $folderName created."
        Build2
    }
}

function build2
{
    cd build
    cmake ..
    cmake --build . --config Release
}

install-dependences
build
