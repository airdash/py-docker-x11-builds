#FIXME: The whole thing

FROM pydockerx11/base/ubuntu:20.04
USER root
RUN apt-get clean && apt-get update && apt-get dist-upgrade -y 

# Add basic packages
RUN apt-get install software-properties-common strace libc6:i386 libstdc++6:i386 dumb-init -y

# Add fonts
RUN apt-get install fonts-beng fonts-beng-extra fonts-dejavu-core fonts-deva fonts-deva-extra fonts-droid-fallback fonts-freefont-ttf fonts-gargi fonts-gubbi fonts-gujr fonts-gujr-extra fonts-guru fonts-guru-extra fonts-hack fonts-indic fonts-kacst fonts-kacst-one fonts-kalapi fonts-khmeros-core fonts-knda fonts-lao fonts-lato fonts-liberation fonts-liberation2 fonts-lklug-sinhala fonts-lohit-beng-assamese fonts-lohit-beng-bengali fonts-lohit-deva fonts-lohit-gujr fonts-lohit-guru fonts-lohit-knda fonts-lohit-mlym fonts-lohit-orya fonts-lohit-taml fonts-lohit-taml-classical fonts-lohit-telu fonts-mlym fonts-nakula fonts-navilu fonts-noto-cjk fonts-noto-color-emoji fonts-noto-core fonts-noto-hinted fonts-noto-mono fonts-noto-ui-core fonts-noto-unhinted fonts-opensymbol fonts-orya fonts-orya-extra fonts-pagul fonts-quicksand fonts-sahadeva fonts-samyak-deva fonts-samyak-gujr fonts-samyak-mlym fonts-samyak-taml fonts-sarai fonts-sil-abyssinica fonts-sil-padauk fonts-smc fonts-smc-anjalioldlipi fonts-smc-chilanka fonts-smc-dyuthi fonts-smc-gayathri fonts-smc-karumbi fonts-smc-keraleeyam fonts-smc-manjari fonts-smc-meera fonts-smc-rachana fonts-smc-raghumalayalamsans fonts-smc-suruma fonts-smc-uroob fonts-taml fonts-telu fonts-telu-extra fonts-teluguvijayam fonts-thai-tlwg fonts-tibetan-machine fonts-tlwg-garuda fonts-tlwg-garuda-ttf fonts-tlwg-kinnari fonts-tlwg-kinnari-ttf fonts-tlwg-laksaman fonts-tlwg-laksaman-ttf fonts-tlwg-loma fonts-tlwg-loma-ttf fonts-tlwg-mono fonts-tlwg-mono-ttf fonts-tlwg-norasi fonts-tlwg-norasi-ttf fonts-tlwg-purisa fonts-tlwg-purisa-ttf fonts-tlwg-sawasdee fonts-tlwg-sawasdee-ttf fonts-tlwg-typewriter fonts-tlwg-typewriter-ttf fonts-tlwg-typist fonts-tlwg-typist-ttf fonts-tlwg-typo fonts-tlwg-typo-ttf fonts-tlwg-umpush fonts-tlwg-umpush-ttf fonts-tlwg-waree fonts-tlwg-waree-ttf fonts-ubuntu fonts-urw-base35 fonts-yrsa-rasa -y

# Xorg stuff
RUN apt-get install -y kmod libgtk2.0 libgtk-3.0 libxext6 libx11-6 libxv1 mesa-utils libegl1 libgegl-common libglu1-mesa \
            libxcursor1 libgtk-3-0 libappindicator3-1 libnotify4 libnss3 libxss1 libxtst6 xdg-utils \
            libatspi2.0-0 kde-cli-tools trash-cli libglib2.0-bin gvfs-bin libx11-dev \
            libc++1 libappindicator1 libgconf-2-4 gcc gcc-multilib ffmpeg yaru-theme-gnome-shell gnome-themes-extra -y

USER sandbox
