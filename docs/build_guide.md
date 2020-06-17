# Build iSulad from source

If you intend to contribute on iSulad. Thanks for your effort. Every contribution is very appreciated for us.

## Install basic dependencies on different distribution

These dependencies are required for build:

### install basic dependencies based on Centos distribution
```sh
$ sudo yum --enablerepo='*' install -y automake autoconf libtool cmake make libcap libcap-devel libselinux libselinux-devel libseccomp libseccomp-devel yajl-devel git libcgroup tar python3 python3-pip device-mapper-devel libarchive libarchive-devel libcurl-devel zlib-devel glibc-headers openssl-devel gcc gcc-c++ systemd-devel systemd-libs golang libtar libtar-devel
```

### install basic dependencies based on Ubuntu distribution
```sh
$ sudo apt install -y libtool automake autoconf cmake make pkg-config libyajl-dev zlib1g-dev libselinux-dev libseccomp-dev libcap-dev libsystemd-dev git libcurl4-gnutls-dev openssl libdevmapper-dev golang python3 libtar libtar-dev
```

## Build and install other dependencies from source
These dependencies may not be provided by your package manager. So you need to build them from source.

### set ldconfig and pkgconfig
```
$ export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
$ export LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:$LD_LIBRARY_PATH
$ sudo -E echo "/usr/local/lib" >> /etc/ld.so.conf
```
### build and install protobuf
```
$ git clone https://gitee.com/src-openeuler/protobuf.git
$ cd protobuf
$ tar -xzvf protobuf-all-3.9.0.tar.gz
$ cd protobuf-3.9.0
$ sudo -E ./autogen.sh
$ sudo -E ./configure
$ sudo -E make -j $(nproc)
$ sudo -E make install
$ sudo -E ldconfig
```

### build and install c-ares
```
$ git clone https://gitee.com/src-openeuler/c-ares.git
$ cd c-ares
$ tar -xzvf c-ares-1.15.0.tar.gz
$ cd c-ares-1.15.0
$ sudo -E autoreconf -if
$ sudo -E ./configure --enable-shared --disable-dependency-tracking
$ sudo -E make -j $(nproc)
$ sudo -E make install
$ sudo -E ldconfig
```

### build and install grpc
```
$ git clone https://gitee.com/src-openeuler/grpc.git
$ cd grpc
$ tar -xzvf grpc-1.22.0.tar.gz
$ cd grpc-1.22.0
$ sudo -E make -j $(nproc)
$ sudo -E make install
$ sudo -E ldconfig
```

### build and install http-parser
```
$ git clone https://gitee.com/src-openeuler/http-parser.git
$ cd http-parser
$ tar -xzvf http-parser-2.9.2.tar.gz
$ cd http-parser-2.9.2
$ sudo -E make -j CFLAGS="-Wno-error"
$ sudo -E make CFLAGS="-Wno-error" install
$ sudo -E ldconfig
```

### build and install libwebsockets
```
$ git clone https://gitee.com/src-openeuler/libwebsockets.git
$ cd libwebsockets
$ tar -xzvf libwebsockets-2.4.2.tar.gz
$ cd libwebsockets-2.4.2
$ patch -p1 -F1 -s < ../libwebsockets-fix-coredump.patch
$ mkdir build
$ cd build
$ sudo -E cmake -DLWS_WITH_SSL=0 -DLWS_MAX_SMP=32 -DCMAKE_BUILD_TYPE=Debug ../
$ sudo -E make -j $(nproc)
$ sudo -E make install
$ sudo -E ldconfig
```

## Build and install specific versions dependencies from source 
iSulad depend on some specific versions dependencies.

### build and install lxc
```
$ git clone https://gitee.com/src-openeuler/lxc.git
$ cd lxc
$ tar -zxf lxc-4.0.1.tar.gz
$ ./apply-patches
$ cd lxc-4.0.1
$ sudo -E ./autogen.sh
$ sudo -E ./configure
$ sudo -E make -j
$ sudo -E make install
```

### build and install lcr
```
$ git clone https://gitee.com/openeuler/lcr.git
$ cd lcr
$ mkdir build
$ cd build
$ sudo -E cmake ..
$ sudo -E make -j
$ sudo -E make install
```

### build and install clibcni
```
$ git clone https://gitee.com/openeuler/clibcni.git
$ cd clibcni
$ mkdir build
$ cd build
$ sudo -E cmake ..
$ sudo -E make -j
$ sudo -E make install
```

### build and install iSulad-img
```
$ git clone https://gitee.com/openeuler/iSulad-img.git
$ cd iSulad-img
$ ./apply-patch
$ sudo -E make
$ sudo -E make install
```

### build and install iSulad
```sh
$ git clone https://gitee.com/openeuler/iSulad.git
$ mkdir build
$ cd build
$ sudo -E cmake ..
$ sudo -E make
$ sudo -E make install
```