# android-check

[![sampctl](https://img.shields.io/badge/sampctl-android--check-2f2f2f.svg?style=for-the-badge)](https://github.com/ff-agus44/android-check)

A forked project from original source code my master Fairuz :pray:

```
This repository is not mine, and I'm not claiming the credit for this repo.
I just forked it so I can easily find it in the future.
So don't you ever call me a repo stealer >:[

- Sync07
```

## Installation

Simply install to your project:

```bash
sampctl package install ff-agus44/android-check
```

Include in your code and begin using the library:

```pawn
#include <android-check>
```

And before running, make sure you have this line:
```
local: true
```

in your pawn.json or pawn.yaml if you are sampctl users, otherwise just ignore this.

## Usage

```pawn
#include <a_samp>
#include <android-check>

public OnClientChecked(playerid, Client:type)
{
	if (type == CLIENT_TYPE_ANDROID)
	{
		return Ban(playerid);
	}
	return 1;
}

```

***NOTE:** you cannot use this inside OnPlayerConnect, that is why i made a custom one :>*

## Testing

To test, simply run the package:

```bash
sampctl package run
```
