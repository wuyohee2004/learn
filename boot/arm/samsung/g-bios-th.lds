ENTRY(GTopHalfEntry)

SECTIONS
{
	.text 0x0:
	{ 
		GTopHalfEntry = .;
		*(.text)
	}

	.data ALIGN(4):
	{ 
		data_start = .;
		*(.data)
		. = ALIGN(4);
	}

	.bss ALIGN(4):
	{
		bss_start = .;
		*(.bss)
	}

	gbios_th_end = .;
}
