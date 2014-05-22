module A13 = Set.Make(String);;
exception A1;;
let a2 = ref A13.empty;;
let a3 = ref [];;
let a11 a6 a5 = A13.diff a5 (List.fold_left (fun a4 (a9,a10) -> A13.add a9 a4) A13.empty a6);;
let rec a12 a4 a5 a6 = begin
    if a5 = A13.empty then a4
    else let a7 = a11 a6 a5 in
	 if a7 = A13.empty then raise A1
	 else let a8 = A13.min_elt a7 in
	      a12 (a8 :: a4) (A13.remove a8 a5) (List.filter (fun (a9,a10) -> (a9 <> a8)&&(a10 <> a8)) a6)
  end;;
  try
    while true do
      let a9 = read_line () in
      let a10 = read_line () in
      a2 := A13.add a9 (A13.add a10 !a2);
      a3 := (a9,a10) :: !a3;
    done
  with _ -> try
      List.iter print_endline (List.rev (a12 [] !a2 !a3))
    with A1 -> print_endline "cycle"
