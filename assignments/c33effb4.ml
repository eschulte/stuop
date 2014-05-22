let a1 = ref [] in
    try
      while true do
	a1 := List.append !a1 [(read_line ())]
      done
    with _ -> begin
	let rec a10 a2 a8 = match a2 with
	  | [] -> a8
	  | hd :: tl when hd = a8 && (not ((List.hd tl) = "")) -> ""
	  | hd :: tl -> a10 (List.tl tl) a8
	in
	let rec a11 a2 a8 = match a2 with
	  | [] -> []
	  | hd :: tl when hd = a8 -> "" :: a11 tl a8
	  | hd :: tl -> hd :: a11 tl a8
	in
	let rec a12 a2 = match a2 with
	  | [] -> false
	  | hd :: tl when hd = "" -> a12 tl
	  | hd :: tl -> true
	in
	let rec a13 a2 = match a2 with
	  | [] -> []
	  | hd :: tl when hd = "" -> a13 tl
	  | hd :: tl -> hd :: a13 tl
	in
	let a3 = a1 in
	let a4 = ref [] in
	let a5 = ref [] in
	let a9 = List.map (a10 !a3) !a3 in
	a4 := a13 a9;
	while not (!a4 = []) do
	  a4 := List.sort (fun a6 a7 -> compare a6 a7) !a4;
	  let a8 = (List.hd !a4) in
	  a4 := (List.tl !a4);
	  a3 := a11 !a3 a8;
	  a5 := List.append !a5 [a8];
	  let a9 = List.map (a10 !a3) !a3 in
	  a4 := a13 a9
	done;
	if (a12 !a3) then
	  print_endline "cycle"
	else
	  List.iter print_endline !a5
      end
