Package: gtest:x64-windows@1.15.2

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.42.34435.0
-    vcpkg-tool version: 2024-09-30-ab8988503c7cffabfd440b243a383c0a352a023d
    vcpkg-readonly: true
    vcpkg-scripts version: 2960d7d80e8d09c84ae8abf15c12196c2ca7d39a

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached google-googletest-v1.15.2.tar.gz.

```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "shooting-project",
  "version": "2.5.0",
  "dependencies": [
    {
      "name": "gtest",
      "platform": "windows"
    }
  ],
  "builtin-baseline": "65be7019941e1401e02daaba0738cab2c8a4a355"
}

```
</details>
