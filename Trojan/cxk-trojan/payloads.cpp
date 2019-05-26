#include "payloads.h"

Payload_Info autorun_payloads[] = { 
	Payload_Info{ "Show barrages on screen", payload_barrages, 0}
};

int autorun_payloads_count = sizeof(autorun_payloads) / sizeof(Payload_Info);
