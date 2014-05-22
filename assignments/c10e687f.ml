let compare a1 a2 =
  match a1 with
    a1 when List.length a1 > List.length a2 -> 1
   |a1 when List.length a1 < List.length a2 -> -1
   |a1 -> String.compare (List.hd a1) (List.hd a2);;
let rec a8 a6 =
  match List.sort compare a6 with
    [] -> []
   |a6 -> match List.hd a6 with
            hd when List.length hd != 1 -> [""]
           |hd -> List.hd hd :: a8 (List.map (List.filter (fun a3 -> (String.compare a3  (List.hd hd)) != 0))  (List.tl a6));;
open Printf;;
let a4 = [["a";"b";"c"];["b";"c"];["c"];["f";"c"];["d";"c"]];;
let a9 a5 a6 = String.compare a5 (List.hd a6) = 0;;
let rec a10 a6 =
  match a6 with
    [] -> ()
   |a6 when List.mem "" a6 -> print_endline "cycle"
   |a6 -> List.iter print_endline a6;;
let rec a11 a6 a7 =
  match a7 with
    [] -> a6
   |a7 -> a11 (List.map (fun  a6 -> (if (String.compare (List.hd a6) (List.hd a7) = 0) then List.append a6 [List.hd (List.tl a7)] else a6)) a6) (List.tl (List.tl a7));;
let rec a12 a7 =
  match a7 with
    [] -> []
   |a7 -> match (List.hd a7, a12 (List.tl a7)) with
            (a5, a6) when (List.exists (a9 a5) a6) -> a6
           |(a5, a6) -> [a5] :: a6;;
let a7 = ref [] in
    try
      while true do
        a7 := List.append !a7 [(read_line ())]
      done
    with _ -> begin
        a10 (a8 (a11 (a12 !a7) !a7));
        ()
      end;;
