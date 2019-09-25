## multiply two digits

,>,
----- ----- ----- -----
----- ----- ----- -----
----- ---
<
----- ----- ----- -----
----- ----- ----- -----
----- ---

## One and Zero now have both numbers in number form

Zero::times do
[
	One::times do
	>
	[	
		>+ inc Two
		>+ inc Three
		<<- dec One
	]
	
	## reset One to hold the original number
	Two::times do
	>
	[
		<+ inc One
		>- dec Two
	]
	<<- dec Zero
]

## Convert Three to ascii digit form

>>>
+++++ +++++ +++++ +++++
+++++ +++++ +++++ +++++
+++++ +++

. print Three

