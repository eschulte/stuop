module A20 = Map.Make(String);;
module A21 = Set.Make(String);;
let a17 a8 = List.sort (fun a1 a2 -> if a1 < a2 then -1 else 1) (A20.fold (fun a3 a4 a9 -> if (A21.is_empty a4) then (a3 :: a9) else a9) a8 []);;
let a18 a8 a5 = A20.fold (fun a6 a7 a9 -> A20.add a6 (A21.remove a5 a7) a9) a8 A20.empty;;
let rec a19 a8 a9 =
  let a10 = a17 a8 in
  if List.length a10 == 0 then a9
  else let a11 = List.hd a10 in a19 (a18 (A20.remove a11 a8) a11) (a9@[a11]) ;;
let a12 = ref A20.empty;;
  try
    while true do
      let a13 = read_line() in
      let a14 = read_line() in
      a12 := 	if A20.mem a13 !a12
		then A20.add a13 (A21.add a14 (A20.find a13 !a12)) !a12
		else A20.add a13 (A21.singleton a14) !a12;
      a12 := 	if A20.mem a14 !a12
		then !a12
		else A20.add a14 (A21.empty) !a12;
    done
  with _ -> begin
      let a15 = A20.cardinal !a12 in
      let a16 = a19 !a12 [] in
      if List.length a16 == a15 then List.iter print_endline a16 else print_endline "cycle";
    end
