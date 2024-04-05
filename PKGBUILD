# Maintainer: Your Name <miikesmith@tuta.io>
pkgname=sysmon
pkgver=1.0
pkgrel=1
pkgdesc="Real-time system monitoring tool for Arch Linux"
arch=('x86_64')
url="https://github.com/mjrxyz/sysmon"
license=('GPL')
depends=('gcc')
source=("sysmon.c")
sha256sums=('SKIP')

build() {
    gcc -o sysmon sysmon.c
}

package() {
    install -Dm755 sysmon "${pkgdir}/usr/bin/sysmon"
}
